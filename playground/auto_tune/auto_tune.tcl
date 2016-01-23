#!/bin/env tclsh
package require Itcl
package require struct::set
catch {namespace import  ::itcl::* }


#---- utility functions

proc splitS { line } {
    set rts [list]
    set ts [split $line]
    foreach t $ts {
        if {$t == ""} {
            continue
        }
        lappend rts $t
    }
    return $rts
}

#--- skip space by default
#    output tokens will include the character define din "charSet"
#-
proc splitC { line charSet } {
    set rts [list]
   
    set token ""
    for {set idx 0} {$idx < [string length $line]} {incr idx} {
        set c [string index $line $idx] 
        set matched "" 

        #--- skip space by default
        #
        if {$c == " " || $c == "\t"} {
            if { $token != "" } {
                lappend rts $token    
                set token ""
            }
            continue
        }
        
        for {set i2 0} {$i2 < [string length $charSet]} {incr i2} {
            set c2 [string index $charSet $i2]
            if { $c == $c2 } {
                set matched $c2
                break
            }
        }

        if {$matched != ""} {
            if { $token != "" } {
                lappend rts $token
                lappend rts $matched
            } else {
                lappend rts $matched
            }
            set token ""
        } else {
            set token "${token}$c"
        }
    }

    if {$token != ""} {
        lappend rts $token 
    }

    return $rts
}



#----
#  _type : to tell which kind of token this is
#  _str  : the parsed string for the token
#  _txt  : this is tricky, to save space/newline before the current token
#  _line : line number
#
class Token {
    protected variable _type
    protected variable _str
    protected variable _txt
    protected variable _line

    constructor { type {str ""} {line 0} } {
        set _type $type
        set _str  $str
        set _line $line
        set _txt ""
    }

    public method getType {} { return $_type }  
    public method getStr {} { return $_str }  
    public method getLine {} { return $_line }  
    public method getTxt {} { return $_txt }  

    public method setType { type } { set _type type }  
    public method setStr { str } { set _str $str }  
    public method setLine { line } { set _line $line }  
    public method setTxt { txt } { set _txt $txt }  
}


class MiptTokenizer {
    protected variable _fname
    protected variable _tokens
    protected variable _patterns
    protected variable _matched
    protected variable _lineIdx

    constructor { fname } {
        set _fname $fname
        set _tokens [list]
        set _patterns [list]
        set _lineIdx 1
    }

    public method add_pattern { pattern cb } {
        lappend _patterns [list $pattern $cb]
    }

    public method add_tokken { token } {
        lappend _tokens $token
    }

    #---
    # Scan through characters and try to find which "regular expression" can match.
    # Once we find a matched regular expression, we invoke the corresponding callback script
    #
    #   $tokenizer add_pattern {[\t ]+}     {     add_token SPACE          $_matched $_lineIdx }
    #   $tokenizer add_pattern {\n}         {     add_token NEWLINE        $_matched $_lineIdx; incr _lineIdx }
    #   $tokenizer add_pattern {=}          {     add_token EQ             $_matched $_lineIdx }
    #   $tokenizer add_pattern {\{}         {     add_token LBRACE         $_matched $_lineIdx }
    #   $tokenizer add_pattern {\}}         {     add_token RBRACE         $_matched $_lineIdx }
    #   $tokenizer add_pattern {#}          {     add_token MIPT_COMMENT   $_matched $_lineIdx }
    #   $tokenizer add_pattern {//}         {     add_token SVRF_COMMET    $_matched $_lineIdx }
    #   $tokenizer add_pattern {[^\t\n \{\}=#]+}  {     add_token STRING         $_matched $_lineIdx }

    public method process {} {
        set fp [open $_fname]
        set content [read $fp]
        close $fp

        set strlen [string length $content]
        set _lineIdx 1

        for {set i 0} {$i < $strlen} {incr i} {
            set char [string index $content $i]
            set tokenStr ""

            if { $char == " " || $char == "\t" } {
                set ii $i
                while { $char == " " || $char == "\t" } {
                    set tokenStr "${tokenStr}${char}"
                    incr ii
                    set char  [string index $content $ii]
                }
                add_token SPACE $tokenStr $_lineIdx
                set i [expr $ii - 1]
            } elseif { $char == "\n" } {
                add_token NEWLINE $char $_lineIdx
                incr _lineIdx
            } elseif { $char == "=" } {
                add_token EQ $char $_lineIdx
            } elseif { $char == "\{" } { 
                add_token LBRACE $char $_lineIdx
            } elseif { $char == "\}" } { 
                add_token RBRACE $char $_lineIdx
            } elseif { $char == "#" } { 
                add_token MIPT_COMMENT $char $_lineIdx
            } elseif { $char == "/" } { 
                set ii [expr $i + 1]
                if { [string index $content $ii] == "/" } {
                    add_token SVRF_COMMENT "//" $_lineIdx
                }
                set i $ii
            } else {
                set tokenStr ""
                set ii $i
                while { $char != " " &&  $char != "\t" && $char != "\n" && $char != "#" &&
                        $char != "\{" && $char != "\}" && $char != "#"  && $char != "=" } {
                    set tokenStr "${tokenStr}${char}"
                    incr ii
                    set char  [string index $content $ii]
                }
                add_token STRING $tokenStr $_lineIdx
                set i [expr $ii - 1]
            }
        }
    }

    public method add_token { type matched line } {
        set t ::MiptTokenizer::[::Token #auto $type $matched $line]
        lappend _tokens $t
    }

    public method getTokens {} {
        return $_tokens
    }
}


class MiptBlock {
    protected variable _type
    protected variable _key
    protected variable _value
    protected variable _parentBlock
    protected variable _subBlockMap
    protected variable _subBlocks

    constructor { key {parent "" }} {
        set _key $key
        set _parentBlock ""
        set _value ""
        set _type ""
        set _subBlocks [list] 
        array set _subBlockMap {}

        if { $parent != "" } {
            $parent addBlock $this
        }
    }

    destructor {
        foreach b $_subBlocks {
            delete object $b
        }
        unset _subBlocks 
        array unset _subBlockMap
    }

    public method getKey {} {
        return $_key
    }

    public method getValue {} {
        return $_value
    }

    public method setValue { v } {
        set _value $v
    }


    public method getType {} {
        return $_type
    }

    public method setType { t } {
        set _type $t
    }

    
    public method clone { { clone_parent "" } } {

        set newBlock ::MiptBlock::[MiptBlock #auto $_key $clone_parent]
        $newBlock setType $_type
        $newBlock setValue $_value

        foreach sb $_subBlocks {
            set csb [$sb clone $newBlock] 
        }

        return $newBlock
    }


    public method addBlock { b } {
        set key [$b getKey]
        if { [info exists _subBlockMap($key)] } {
            return -code error "Duplicate key $key"
        } else {
            lappend _subBlocks $b
            set _subBlockMap($key) $b
        }
    }

    public method removeBlock { b } {
        set key [$b getKey]
        set idx [lsearch $_subBlocks $b]
        if { $idx >= 0 } {
            set _subBlocks [lreplace $_subBlocks $idx $idx]
            unset _subBlockMap($key)
        }
    }

    public method search { key } {
        if { [info exists _subBlockMap($key)] } {
            return $_subBlockMap($key) 
        } else {
            set found ""
        }
    }

    public method searchFullScope { keyStr } {
        set keys [split $keyStr "."]
        set curBlock $this

        for {set i 0} {$i < [llength $keys]} {incr i} {
            set key [lindex $keys $i] 
            set b [$curBlock search $key]

            if { $b == "" } {
                return -code error "Cannot find $keyStr at $key"
            } elseif { $i == ([llength $keys]-1) } {
                return $b
            } else {
                set curBlock $b
            }
        }
    }


    public method replace { keyStr value } {

        set keys [split $keyStr "."]

        if { [llength $keys] != 2 } {
            return -code error "Haven't suported anything other than \"A.b\" replacement"
        }

        set bc [search [lindex $keys 0]]

        if { $bc == "" } {
            return -code error "Cannot find \"[lindex $keys 0]\""
        }

        set bc2 [$bc search [lindex $keys 1]]


        if { $bc2 != "" } {
            #-- backup
            $bc2 setValue $value
        } else {
            #-- create temp block
            set bc_tmp ::MiptBlock::[MiptBlock #auto [lindex $keys 1] $bc]
            $bc_tmp setType "prop"
            $bc_tmp setValue $value
        }
    }


    public method toStr {} {
        set myStr ""

        if { $_type == "prop" } {

            set myStr "${myStr}${_key} =${_value}\n"

        } elseif { $_type == "equation" } {

            set myStr "${myStr}equation =  \{$_value\}\n"

        } elseif { $_type == "GLOBAL" }  {
            foreach b $_subBlocks {
                set myStr "${myStr}[$b toStr]" 
            }
        } else {
            #-- layer
            set myStr "${myStr}$_type = $_key \{\n"
            foreach b $_subBlocks {
                set myStr "${myStr}[$b toStr]"
            }
            set myStr "${myStr}\}\n"
        }

        return $myStr
    }


    public method dump {} {
        puts [toStr]
    }
}


class MiptParser {
    protected variable _tokens
    protected variable _firstT
    protected variable _idx
    protected variable _curBlock

    constructor { tokens } {
        set _tokens $tokens

        preprocess 

        set _firstT [lindex $tokens 0]
        set _idx 0
    }

    private method preprocess {} {
     
        set combinedTxt "" 
        set newTokens [list] 

        for {set idx 0} {$idx < [llength $_tokens] } {incr idx} {
             
            set t [lindex $_tokens $idx]
            set type [$t getType]
        
            if { $type == "SPACE" || $type == "NEWLINE" } {
                set combinedTxt "${combinedTxt}[$t getStr]"
        
            } elseif { [$t getType] == "MIPT_COMMENT" }  {
                while { [$t getType] != "NEWLINE" } {
                    set combinedTxt "${combinedTxt}[$t getStr]"
                    incr idx
                    set t [lindex $_tokens $idx]
                }
            } else {
                $t setTxt "${combinedTxt}[$t getStr]"
                set combinedTxt ""
                lappend newTokens $t
            }
        }

        set _tokens $newTokens
    }


    private method match { {type ""} {str ""} } {

        # puts "Rich: matching 1. '$type' 2. '$str' 3. '[$_firstT getType]' 4. '[$_firstT getStr]'"

        if { $type == ""} {
             set t $_firstT
             incr _idx 
             set _firstT [lindex $_tokens $_idx]
             return $t
        } elseif { [$_firstT getType] == $type } {
            if { $str == "" || $str == [$_firstT getStr] } {
                set t $_firstT
                incr _idx 
                set _firstT [lindex $_tokens $_idx]
                return $t
            }
        } 
        return -code error "Parsing error at line [$_firstT getLine] , around [$_firstT getStr]"
    }

    private method peek { idx } {
        return [lindex $_tokens $idx]
    }

    public method parse_equation { tableBlock } {
        # puts "Rich, parse_equation"
        match "STRING" "equation"
        match "EQ"
        set equBlock ::MiptParser::[MiptBlock #auto "equation" $tableBlock]
        $equBlock setType "equation"

        match "LBRACE"
        set depth 1
        set value ""
        while { 1 } {
            set t [match]
            if { [$t getType] == "LBRACE" } {
                incr depth 
            } elseif {[$t getType] == "RBRACE" } {
                incr depth -1 
            }
            
            if { $depth == 0 } {
                break
            } else {
                set value "${value}[$t getTxt]"
            }
        }
        $equBlock setValue $value
    }


    public method parse_table { layerBlock } {
        # puts "Rich, parse_table"
        match "STRING" "table"        
        match "EQ"
        set t_name [match "STRING"]
        set tableBlock ::MiptParser::[MiptBlock #auto [$t_name getStr] $layerBlock]
        $tableBlock setType "table"

        match "LBRACE"

        while { [$_firstT getType] != "RBRACE" } {
            if { [$_firstT getStr] == "equation" } {
                parse_equation $tableBlock
            } else {
                parse_prop $tableBlock
            }
        }
        match "RBRACE"
    }


    public method parse_prop { parentBlock } {
        # puts "Rich, parse_prop"
        set t_name [match "STRING"]
        set propBlock ::MiptParser::[MiptBlock #auto [$t_name getStr] $parentBlock]
        match "EQ"
        $propBlock setType "prop"

        set value ""
        if { [$_firstT getType] == "LBRACE" } {
            set t1 [match "LBRACE"] 
            while { [$_firstT getType] != "RBRACE" } {
                set t [match]
                set value "${value}[$t getTxt]"
            }
            set t2 [match "RBRACE"]
            set value "[$t1 getTxt]$value[$t2 getTxt]"

        } else {
            set t [match]
            set value "${value}[$t getTxt]"
        }

        $propBlock setValue $value
    }

    public method parse_layer { parentBlock } {
        # puts "Rich, parse_layer"
        set t_layer [match "STRING"] 

        #--- workaround the weird problem
        #
        if { [$_firstT getType] == "EQ" } {
            match "EQ"
        }

        set t_name  [match "STRING"]
        match "LBRACE"

        set layerBlock ::MiptParser::[MiptBlock #auto [$t_name getStr] $parentBlock]
        $layerBlock setType [$t_layer getStr]

        while { [$_firstT getType] != "RBRACE" } {
            if { [$_firstT getStr] == "table" } {
                parse_table $layerBlock
            } else {
                parse_prop $layerBlock
            }
        }
        match "RBRACE"
    }


    #---
    # 1.  prop = token 
    # 2.  prop = { tokens }
    # 3.  layer = a { stmts }
    # 4.  equation = a { ... }
    # 5.  table = a { stmts  }
 
    public method parse {} {
       
        set gb ::MiptParser::[MiptBlock #auto ""]
        $gb setType "GLOBAL"

        while { $_idx < [llength $_tokens] } {

            set str   [$_firstT getStr]

            if { $str == "dielectric" } {
                parse_layer $gb
            } elseif {$str == "conductor" } {
                parse_layer $gb
            } elseif {$str == "base" } {
                parse_layer $gb
            } elseif {$str == "multigate" } {
                parse_layer $gb
            } elseif {$str == "li" } {
                parse_layer $gb
            } elseif {$str == "device_li" } {
                parse_layer $gb
            } elseif {$str == "diffusion" } {
                parse_layer $gb
            } elseif {$str == "poly" } {
                parse_layer $gb
            } elseif {$str == "seed" } {
                parse_layer $gb
            } elseif {$str == "via" } {
                parse_layer $gb
            } elseif {$str == "base_via" } {
                parse_layer $gb
            } elseif {$str == "contact" } {
                parse_layer $gb
            } elseif {$str == "resistor" } {
                parse_layer $gb
            } elseif {$str == "derived" } {
                parse_layer $gb
            } else {
                parse_prop $gb
            }
        }

        return $gb
    }

}



#---- read in configure file
# ex.
# space with everything
#
# runs = {
#   names = {                            ori     exp1   exp2   }
#   props = { n_gpoly_svt.rsd_enclosure    -     0.002  0.003
#             n_gpoly_svt.rsd_enclosure    -     0.002  0.003
#             n_gpoly_svt.rsd_enclosure    -     0.002  0.003
#           }    
# }
#

class Experiment {
    protected variable _name
    protected variable _props
    protected variable _arcx_config 
    protected variable _qa_script
    protected variable _cal_script
    protected variable _dir_map_v2g
    protected variable _calibre_source

    constructor { name } {
        set _name $name
        set _props [list]
        set  _arcx_config  ""
        set  _qa_script ""
        set  _cal_script ""
        set  _dir_map_v2g ""
        set  _calibre_source ""
    }

    public method getName {} {
        return $_name
    }

    public method addProp { name value } {
        lappend _props [list $name $value]
    }

    public method getProps {} {
        return $_props
    }

    public method set_arcx_config { arcx_config } {
        set _arcx_config $arcx_config
    }

    public method set_qa_script   { qa_script } {
        set _qa_script $qa_script
    }

    public method set_cal_script  { cal_script } {
        set _cal_script $cal_script
    }

    public method set_dir_map_v2g { dir_map_v2g } {
        set _dir_map_v2g $dir_map_v2g
    }

    public method set_calibre_source { calibre_source } {
        set _calibre_source $calibre_source
    }


    public method get_arcx_config { } {
        return $_arcx_config
    }

    public method get_qa_script   { } {
        return $_qa_script
    }

    public method get_cal_script  { } {
        return $_cal_script
    }

    public method get_dir_map_v2g { } {
        return $_dir_map_v2g
    }

    public method get_calibre_source { } {
        return $_calibre_source
    }


    public method add_env_to_script { script envLine } {

        #-- assume it has "#!/bin/csh .." as the beginning
        #
        set shellIdx [string first "csh" $script ]
        set firstNewLineIdx [string first "\n" $script $shellIdx] 

        set s1 [string range $script 0 $firstNewLineIdx]
        set s2 [string range $script [expr $firstNewLineIdx + 1] end]
        set newStr "${s1}${envLine}\n${s2}"

        return $newStr
    }
 
    public method dump { {fp stdout} } {
        puts $fp "---- $_name ----"
        # puts $fp "    Arcx config : [get_arcx_config]"
        # puts $fp "    dir map : [get_dir_map_v2g]"
        # puts $fp "    Calibration script : [get_cal_script]"
        # puts $fp "    QA script : [get_qa_script]"
        puts $fp ""

        foreach prop $_props {
            puts $fp "    [lindex $prop 0] [lindex $prop 1]" 
        }
    }
}


class ConfigSetting {
    protected variable _exps
    protected variable _ga_config
    protected variable _arcx_config
    protected variable _qa_script
    protected variable _calibration_script
    protected variable _dir_map_v2g
    protected variable _calibre_source

    constructor { configfile } {

        #--- variables defined in config_tcl
        #
        set _exps     [list]

        #--- read in the config file
        #
        source $configfile
        eval $config_tcl

        #--- error checking
        #
        if { ![info exists calibration_script] ||
             ![info exists qa_script] ||
             ![info exists calibre_source] ||
             ![info exists dir_map_v2g] ||
             ![info exists arcx_config] } {

            puts "ERROR! Some key variables are not defined in config file"
            puts "   There should be 'calibration_script' 'qa_script' 'calibre_source' 'dir_map_v2g' 'arcx_config'"
            return -code error
        }

        set _calibration_script [string trim $calibration_script]
        set _qa_script [string trim $qa_script]
        set _arcx_config [string trim $arcx_config]
        set _dir_map_v2g [string trim $dir_map_v2g]
        set _calibre_source [string trim $calibre_source]
      
        check_csh_script $_qa_script 
        check_csh_script $_calibration_script
        
        if {[info exists ga_config]} {
            
            puts "INFO!'ga_config' is defined, ignore 'exp_name' and 'exp_prop' setting"
            set _ga_config $ga_config

        } else {
            set _ga_config ""

            if {![info exists exp_names] || ![info exists exp_props]} {
                puts "ERROR! 'exp_names' or 'exp_props' is not defined"
                return -code error
            }

            #--- create experiment object and insert it into internal _exp list 
            #
            foreach name $exp_names {
                #-- this would create exp object and add into _exps
                makeExp $name
            }

            set propName ""
            set expCount [llength $_exps]
            set expIdx 0

            foreach ts $exp_props {
                set propName [lindex $ts 0]
                set props [lrange $ts 1 end]

                for {set i 0} {$i < [llength $props]} {incr i} {
                    set exp [lindex $_exps $i]
                    set prop [lindex $props $i]
                    $exp addProp $propName $prop
                }
            }
        }
    }

    public method makeExp { name } {
        set exp ::ConfigSetting::[::Experiment #auto $name]
        $exp set_qa_script $_qa_script
        $exp set_cal_script $_calibration_script
        $exp set_calibre_source $_calibre_source
        $exp set_arcx_config $_arcx_config
        $exp set_dir_map_v2g $_dir_map_v2g
        lappend _exps $exp
        return $exp
    }

    public method check_csh_script { script } {
        #--- the first line of the script must start with "#!/bin/csh"
        #
        set lines [split $script "\n"]
        set line1 [lindex $lines 0]
        if { [string first "#!/bin/csh" $line1] != 0 } {
            puts "ERROR, shell script does not start with \"#!/bin/csh\""
            puts "   $script"
            return -code error
        }
    }

    public method clearExps {} {
        foreach e $_exps {
            delete object $e
        }
        set _exps [list]
    }

    public method getGAConfig {} {
        return $_ga_config
    }

    public method getExps {} {
        return $_exps
    }

    public method dump {} {
        foreach exp $_exps {
            $exp dump
            puts ""
        }
    }
}


class QARun {
    protected variable _name
    protected variable _miptContent
    protected variable _calpath
    protected variable _qapath
    protected variable _parentpath
    protected variable _dir_map_v2g
    protected variable _arcx_config
    protected variable _cal_script
    protected variable _qa_script
    protected variable _calibre_source
    protected variable _cal_finish_tag
    protected variable _qa_finish_tag

    constructor { name miptContent calibresource dirmap arcx calscript qascript } {
        set _name $name 
        set _miptContent $miptContent
        set _parentpath [pwd]
        set _qapath "${_parentpath}/$_name"
        set _calpath "${_qapath}/calibration"
        set _qa_finish_tag "${_qapath}/.qa_end"
        set _cal_finish_tag "${_calpath}/.calibration_end"
        set _dir_map_v2g $dirmap
        set _arcx_config $arcx
        set _cal_script $calscript
        set _qa_script $qascript
        set _calibre_source $calibresource
    }

    public method getName {} { return $_name }
    public method get_qapath {} { return $_qapath }
    public method get_calpath {} { return $_calpath }

    public method exist_run_dir {} {  
        if { [file exists $_qapath] } {
            return 1
        } else {
            return 0
        }
    }

    public method exist_cal_dir {} {  
        if { [file exists ${_calpath}] } {
            return 1
        } else {
            return 0
        }
    }

    private method gen_calibration_dofile {} {
        
        if {$_cal_script != ""} {
            
            #--- Replace mipt file name to the current one
            #
            regsub {[ \t]+[^ \t]+\.mipt[ \t]+} $_cal_script " ${_name}.mipt " _cal_script 

            #--- seperate the original script, so that we could insert stuff
            #
            set lines [split $_cal_script "\n"]
            set line0 [lindex $lines 0]
            # set lineRest ""
            # for {set i 1} {$i < [llength $lines]} {incr i} {
            #     set lineRest "${lineRest}[lindex $lines $i]\n"
            # }
            set lineRest [join [lrange $lines 1 end] "\n"]

            set fp [open "${_calpath}/dofile" "w"]
            puts $fp "${line0}\n"
            puts $fp "cd ${_calpath}"
            puts $fp "${lineRest}\n"

            #--- add stop flag
            puts $fp "touch ${_cal_finish_tag}"

            close $fp
            file attributes "${_calpath}/dofile" -permissions 0755 
        } else {
            puts "ERROR: Empty cal_script"
            return -code error
        }
    }

    public method run_calibration {} {

        if {[file exists $_qapath]} {
            file delete -force $_qapath
        }

        puts "Running calibration at $_qapath"

        file mkdir $_qapath
        file mkdir "${_calpath}"

        set fp [open "${_calpath}/${_name}.mipt" "w"]
        puts $fp $_miptContent
        close $fp

        gen_calibration_dofile
        exec "${_calpath}/dofile" &
    }

    private method gen_local_calibre_source_file { filename } {
        set fp [open ${_qapath}/$filename w]
        puts $fp $_calibre_source
        close $fp
    }

    private method gen_local_arcx_file {} {

        #--- 1. gen the calibre source file
        set calibre_source_name "csh.calibre.everest.2015.3"
        gen_local_calibre_source_file $calibre_source_name

        #--- 2. replace the arcx.cfg 
        regsub {TOOL_VERSION_RCX[ \t]*=[ \t]*([^ \t\n]*)} $_arcx_config "TOOL_VERSION_RCX = ${_qapath}/$calibre_source_name" _arcx_config
        regsub {RCX_RULES[ \t]*=[^\n]+} $_arcx_config "RCX_RULES = ${_calpath}/rules" _arcx_config 

        set fp [open "${_qapath}/arcx.cfg" w] 
        puts $fp $_arcx_config
        close $fp
    }


    private method gen_local_dirmap_file {} {
        set fp [open "${_qapath}/dir_map_v2g" w]
        puts $fp $_dir_map_v2g
        close $fp
    }    

    private method gen_qa_dofile { } {

        gen_local_arcx_file
        gen_local_dirmap_file

        if {$_qa_script != ""} {
           
            #--- prepare dofile
            set fp [open "${_qapath}/dofile" "w"]

            set lines [split $_qa_script "\n"]
            set line0 [lindex $lines 0]
            # set lineRest ""
            # for {set i 1} {$i < [llength $lines]} {incr i} {
            #     set lineRest "${lineRest}[lindex $lines $i]\n"
            # }
            set lineRest [join [lrange $lines 1 end] "\n"]

            #--- insert while loop to wait for calibration
            #
            set _qa_script "${line0}\n \
                            sleep 5 \n \
                            while ( ! -e \"${_cal_finish_tag}\" ) \n \
                                echo \"Waiting calibraton: ${_cal_finish_tag} \" \n \
                                sleep 10 \n \
                            end \n \
                            cd ${_qapath} \n \
                            ${lineRest} \n \
                            touch ${_qa_finish_tag} \n" 

            puts $fp $_qa_script
            close $fp
            file attributes "${_qapath}/dofile" -permissions 0755 
        } else {
            puts "ERROR: Empty qa_script"
            return -code error
        }
    }

    public method run_qa {} {
        gen_qa_dofile 
        exec ${_qapath}/dofile &
    }


    public method is_qa_finished {} {
        if { [file exists "${_qapath}/.qa_end"]}  {
            return 1
        } else {
            return 0
        }
    }

    public method is_cal_finished {} {
        if { [file exists "${_calpath}/.calibration_end"]}  {
            return 1
        } else {
            return 0
        }
    }

}


proc splitS { str } {
    set tokens [split $str " \t"]
    set retTokens [list]

    foreach t $tokens {
        if {$t != ""} {
            lappend retTokens $t
        }
    }
    return $retTokens
}

#---- grab QA result

class QATable {
    protected variable _name
    protected variable _rowIdx
    protected variable _colIdx
    protected variable _table

    constructor { name } {
        set _name $name
        set _rowIdx [list]
        set _colIdx [list]
        set _table [list]
    }


    public method addColumnFromTable { aTable colIdx {newColName "---"} } {
        #--- 1. merge row index
        #
        if { [llength $_rowIdx] == 0 } {
            #-- initialize an empty table with enought number of rows
            #
            set _rowIdx [$aTable getRowIdx]
            foreach idx $_rowIdx {
                lappend _table [list]
            } 
        } 

        set newRowIdx [$aTable getRowIdx]
        set newCol [$aTable getCol $colIdx]
        set used [list]

        for {set i 0} {$i < [llength $newRowIdx]} {incr i} {
             lappend used $i 
        }

        #--- 2. merge column to table
        #
        lappend _colIdx $newColName

        set newTable [list]
        for {set i 0} {$i < [llength $_rowIdx]} {incr i} {
            set row [lindex $_table $i] 
            set found [lsearch $newRowIdx [lindex $_rowIdx $i]]

            if { $found != -1 } {
                lappend row [lindex $newCol $found]
                lappend newTable $row
                set used [lreplace $used $found $found -1]
            } else {
                #--- the added column does not have the index
                lappend row "-100%"
                lappend newTable $row
            }
        }

        foreach i $used {
            
            if { $i < 0 } {
                continue
            }

            set row [list]
            set theNewRowIdx [lindex $newRowIdx $i] 
            for {set j 0} {$j<[llength $_colIdx]-1} {incr j} {
                lappend row "-100%"
            }
            lappend _rowIdx $theNewRowIdx
            lappend row [lindex $newCol $i]
            lappend newTable $row

        }

        set _table $newTable
    }


    public method getRowIdx {} {
        return $_rowIdx
    }

    public method getColIdx {} {
        return $_colIdx
    }

    public method setRowIdx { rowIdx } {
        set _rowIdx $rowIdx
    }
    
    public method setColIdx { colIdx } {
        set _colIdx $colIdx
    }

    public method setValues { values } {
        set _table $values 
    }


    public method getEntry { idxRow idxCol } {
        set row [getRow $idxRow]
        set entry [lindex $row [getCol $idxCol]]
        return $entry
    }

    public method getRow { idx } {
        if { $idx == "end" } {
            return [lindex $_table end]
        } elseif { ![string is integer $idx] } {
            set idx [lookup "row" $idx] 
        }
        return [lindex $_table $idx]
    }

    public method getCol { idx } {
        if { $idx == "end" } {
            set idx "end"
        } elseif { ![string is integer $idx] } {
            set idx [lookup "col" $idx] 
        }
        set ret [list]
        foreach row $_table {
            lappend ret [lindex $row $idx]
        }
        return $ret
    }

    public method lookup { type name } {
        set idx [list]
        if { $type == "row" } {
            set idx $_rowIdx 
        } else {
            set idx $_colIdx 
        }
        return [lsearch $idx $name]
    }

    public method print { {fp stdout} } {

        if { [isEmpty] } {
           return
        }
      
        #-- for each column find the biggest
        set len 0
        foreach x [concat $_rowIdx $_name] {
            if { [string length $x] > $len } {
                set len [string length $x]
            } 
        }
        set formatStr "%[expr $len + 3]s"

        for {set i 0} { $i < [llength $_colIdx] } {incr i} {
            set len 0
            set col [getCol $i]
            set col [concat [lindex $_colIdx $i] $col]

            foreach x $col {
                if { [string length $x] > $len } {
                    set len [string length $x]
                }
            }
            set formatStr "$formatStr  %[expr $len + 3]s"
        }

        #--- print out 
        #
        puts $fp [eval format {$formatStr} $_name $_colIdx]
        for {set i 0} {$i < [llength $_rowIdx]} {incr i} {
            set idxName [lindex $_rowIdx $i] 
            set rowTokens [concat $idxName [lindex $_table $i]]
            puts $fp [eval format {$formatStr} $rowTokens]
        } 

    }

    public method isEmpty {} {
        if { [llength $_table] == 0 } {
            return 1
        } else {
            return 0
        }
    }
}


class QAItemReport {
    
    protected variable _name
    protected variable _expName
    protected variable _cc
    protected variable _tc
    protected variable _sp

    protected variable _ccmean
    protected variable _ccdist
    protected variable _tcdist
    protected variable _tcmax
    protected variable _spmax
    protected variable _spdist

    constructor { expname name qapath } {

        set _ccmean "NA"
        set _ccdist "NA"
        set _tcdist "NA"
        set _tcmax "NA"
        set _spmax "NA"
        set _spdist "NA"

        set _expName $expname
        set _name $name 
        set ccfp "$qapath/QC_Cc/Report_QC_Cc_Summary_SCCB3"     
        set tcfp "$qapath/QC_Ct/Report_QC_Ct_Summary_SCCB3"     
        set spfp "$qapath/QC_Spice/Report_QC_Spice_Summary_SCCB3"     
        
        set ccpat {^block[ \t]+net[ \t]+netlistRef[ \t]+}
        set tcpat {^block[ \t]+net[ \t]+netlistRef[ \t]+}
        set sppat {^rep[ \t]+item[ \t]+refReport[ \t]+}
       
        set items [list [list "cc" $ccfp $ccpat]  [list "tc" $tcfp $tcpat] [list "sp" $spfp $sppat]]

        foreach item $items {
            set name [lindex $item 0]
            set fp   [lindex $item 1]
            set pat  [lindex $item 2]
            set table ::QAItemReport::[::QATable #auto name]

            set collect_rows [collectReport $fp $pat]
            if { [llength $collect_rows] > 0 } {
                $table setColIdx [lrange [lindex $collect_rows 0] 1 end]

                set rowIdx [list]
                set rows [list]
                for {set i 1} {$i<[llength $collect_rows]} {incr i} {
                    
                    #--- the last entry is xact number
                    #    We use all front items as our "row index"
                    #
                    set thisRowIdx "[join [lrange [lindex $collect_rows $i] 0 end-3] ","]"
                    lappend rowIdx $thisRowIdx

                    lappend rows [lrange [lindex $collect_rows $i] 1 end]
                }

                $table setRowIdx $rowIdx
                $table setValues $rows
            }

            #--- Remove the "%" character
            #    And also discard all -100% result
            #
            set entries [list]
            foreach a [$table getCol end] {
                regsub {%} $a "" a
                if { $a > -99.99 } {
                    lappend entries $a
                }
            }

            puts "Rich entries $expname $name $entries"

            #--- assign tables and each QA summary
            #
            if { $name == "cc" } {
                set _cc $table
                set _ccmean [getMean $entries]
                set _ccdist [getDist $entries]
            } elseif { $name == "tc" } {
                set _tc $table
                set _tcmax [getMax $entries]
                set _tcdist [getDist $entries]
            } else {
                set _sp $table
                set _spmax [getMax $entries]
                set _spdist [getDist $entries]
            }
        }
    }

    #--- read in the lines in specified file
    #    1. split each line into a list
    #    2. make another list to hold all "line" list
    #    3. NOTE: first line is the table column index
    #
    private method collectReport { itemPath pattern } {
    
        set fpath "$itemPath" 
        if {[file exists $fpath] == 0} {
            return [list]
        }
    
        set fp [open $fpath r]
        set content [read $fp]
        set lines [split $content "\n"]
       
        set collectLines [list]
        set idx 0
        foreach line $lines {
            #--- the is the keyword for cfcco
            if {[regexp $pattern $line]} {
                #--- make the table header the first entry
                #
                while {$line != ""} {
                    lappend collectLines [splitS $line]
                    incr idx
                    set line [lindex $lines $idx]
                }
                return $collectLines
            }
            incr idx
        }
    }

    public method getName {} {
        return $_name
    }

    public method getExpName {} {
        return $_expName
    }

    public method getCcTable {} {
        return $_cc
    }

    public method getCtTable {} {
        return $_tc
    }

    public method getSpTable {} {
        return $_sp
    }

    public method getMax { entries } {
        set max 0
        foreach item $entries {
            if { abs($item) > $max } {
                set max [expr abs($item)]
            } 
        }
    }

    public method getMean { entries } {
        set total 0
        set count 0
        foreach item $entries {
            incr count
            set total [expr $total + $item]
        }

        if { $count > 0 } {
            return [expr $total / $count]
        } else {
            return "NA"
        }
    }

    public method get2std { entries } {

        set mean [getMean $entries]
        set total 0
        set count 0

        foreach item $entries {
            set total [expr $total + (($item-$mean) * ($item-$mean))]
            incr count
        }

        if { $count > 0 } {
            return [expr 2 * sqrt($total/$count)]
        } else {
            return "NA"
        }
    }


    public method getDist { entries } {

        set total 0
        set count 0

        foreach item $entries {
            set total [expr $total + ($item * $item)]
            incr count
        }

        if { $count > 0 } {
            return [expr 2 * sqrt($total/$count)]
        } else {
            return "NA"
        }
    }

    public method get_cc2std {} {
        return $_ccdist
    }

    public method get_tcmax {} {
        return $_tcmax
    }

    public method get_ccmean {} {
        return $_ccmean
    }

    public method get_spmax {} {
        return $_spmax
    }

    public method get_spDist {} {
        return $_spdist
    }

    public method get_ccDist {} {
        return $_ccdist
    }

    public method get_tcDist {} {
        return $_tcdist
    }



    public method print { {fp stdout} } {
        if {[$_cc isEmpty] == 0} {
            $_cc print $fp
        } 

        if {[$_tc isEmpty] == 0} {
            $_tc print $fp
        }

        if {[$_sp isEmpty] == 0} {
            $_sp print $fp
        }
    }
    
}


#--- Each qaItem contains item name and experiment name, 
#    This manager is to compare each item for all exeriments
#    

class QAItemReportMgr {

    protected variable _qaReportItems
    protected variable _itemNames
    
    constructor {} {
        set _qaReportItems [list]
        set _itemNames [list]
    }

    public method addItem { qaItem } {
        set itemName [$qaItem getName]
        set expName [$qaItem getExpName]
        
        if {[lsearch $_itemNames $itemName] < 0} {
            lappend _itemNames $itemName
        }
       
        lappend _qaReportItems $qaItem
    }

    public method genReport {} {

        puts "QA Item : $_itemNames"

        foreach itemName $_itemNames {
            #--- scan all experiment to find the current item
            #
            set colIdx [list]
            set rowIdx [list]
            set rows   [list]

            #--- each item may have 3 different check, cc, tc, sp
            #
            set newCcTbl ::QAItemReportMgr::[::QATable #auto $itemName]
            set newCtTbl ::QAItemReportMgr::[::QATable #auto $itemName]
            set newSpTbl ::QAItemReportMgr::[::QATable #auto $itemName]

            foreach qaReportItem $_qaReportItems {
                if {$itemName == [$qaReportItem getName]} {

                    set expName [$qaReportItem getExpName]

                    set cct [$qaReportItem getCcTable]
                    if { ![$cct isEmpty] } {
                        $newCcTbl addColumnFromTable $cct end $expName
                    }
                    set ctt [$qaReportItem getCtTable]
                    if { ![$ctt isEmpty] } {
                        $newCtTbl addColumnFromTable $ctt end $expName
                    }
                    set spt [$qaReportItem getSpTable]
                    if { ![$spt isEmpty] } {
                        $newSpTbl addColumnFromTable $spt end $expName
                    }

                }
            }

            $newCcTbl print
            puts ""
            $newCtTbl print
            puts ""
            $newSpTbl print
            puts ""
        }
    }
}


proc helpMsg {} {
    puts "Usage:"
    puts "  ./auto_tune.tcl -mipt <mipt> -config <config> \[-overwrite\] \[-turbo N\]"
}


proc parseArgs { argList options } {
    upvar $options nv
    
    for {set idx 0} {$idx < [llength $argList]} {incr idx} {
        set arg [lindex $argList $idx]

        switch -exact -- $arg {
            -mipt    { 
                         incr idx
                         set nv(mipt) [lindex $argList $idx]
                     }

            -config  {
                         incr idx
                         set nv(config) [lindex $argList $idx]
                     }

            -overwrite {
                         set nv(overwrite) 1
                     }

            -turbo   {
                         incr idx
                         set nv(turbo) [lindex $argList $idx]
                     }


            default  {
                         puts "Unknown argument: [lindex $argList $idx]"
                         helpMsg
                         return -code error
                     }
        }
    }
}


proc fileread { fpath } {
    if { ![file exists $fpath] } {
        puts "ERROR: $fpath not found!"
        return -code error
    }
    set fp [open $fpath r]
    set content [read $fp]
    close $fp
    return $content
}


#---- Submit QAs
#
# foreach experiment in configSetting
# 1. get exp setting
# 2. create new miptblock object by replacing properties
# 3. create qa object
# 
# while there's still unfinished qa object
# 1. trigger qa to run
# 2. put object
#
proc submit_qa { miptBlock configSetting { turbo 1 } } {

    $configSetting dump

    #--- Part 1
    #    gen qa objects
    #
    set qas [list]
    foreach exp [$configSetting getExps] {
        # set newParser [$miptParser clone]

        set newBlock [$miptBlock clone]

        foreach prop [$exp getProps] {
            set name [lindex $prop 0]
            set value [lindex $prop 1]

            if { $value == "-" } {
                continue
            }

            set namets [split $name "."]

            if { [lindex $namets 0] == "qa_script" } {
                set script [$exp get_calibre_source]
                set newLine "setenv [lindex $namets 1] $value"
                set script [$exp add_env_to_script $script $newLine]

                $exp set_calibre_source $script

            } elseif { [lindex $namets 0] == "cal_script" } {
                set script [$exp get_cal_script]
                set newLine "setenv [lindex $namets 1] $value"
                set script [$exp add_env_to_script $script $newLine]

                $exp set_cal_script $script

            } else {
                $newBlock replace $name $value
            }
        }

        #--- 1. prepare the qarun objects
        #    2. remove unsed mipt block  
        #
        set qarun [::QARun #auto [$exp getName] [$newBlock toStr] [$exp get_calibre_source] [$exp get_dir_map_v2g] [$exp get_arcx_config] [$exp get_cal_script] [$exp get_qa_script]]
        delete object $newBlock
        lappend qas $qarun
        puts "Generating qaRun object for [$exp getName]"
    }

    #---- part 2.
    #     Invoke qaruns and wait until all of them finished. 
    #
    set waitingList $qas
    set runningList [list]

    while { 1 } {

        if { [llength $runningList] == 0 && [llength $waitingList] == 0 } {
            break
        }

        #---1. collect jobs that are running 
        #
        set temp [list]
        foreach qa $runningList {
            if { 0 == [$qa is_qa_finished] } {
                lappend temp $qa                   
            }
        }
        set runningList $temp

        #---2. pop out approate number of jobs from waitingList
        #      push them into the runningList,
        #
        set newJobCount [expr $turbo - [llength $runningList]]
        set newJobList  [lrange $waitingList 0 [expr $newJobCount-1]]
        set waitingList [lreplace $waitingList 0 [expr $newJobCount-1]]

        #---3. kickoff the added qa objects
        #
        foreach qa $newJobList {
            if { [$qa is_qa_finished] } {
                # if {$fc(overwrite) == 1 } {
                #     $qa run_calibration; #-- this would remove the qa folder
                #     $qa run_qa
                # }
            } else {
                $qa run_calibration
                $qa run_qa
            }
        }

        #---4. combine the new added qa objects to runningList
        #
        set runningList [concat $runningList $newJobList]

        #---5. Wait for a few seconds
        #
        set runningNum 0
        foreach qa $runningList {
            if { ![$qa is_qa_finished] } {
                puts "Waiting for [$qa get_qapath]/.qa_end"
                incr runningNum
            }
        }

        if { $runningNum > 0 || [llength $waitingList] > 0 } { 
            puts "Running experiments: $runningNum ; Waiting experiments : [llength $waitingList]"
            after 5000
        }
    }

    return $qas
}


class Genie {
    protected variable _bits
    protected variable _len
    protected variable _score

    constructor { len {isInitRandom 0} } {
        set _bits ""
        set _len $len
        set _score 0

        for {set i 0} {$i < $len} {incr i} {
            if { $isInitRandom == 0 } {
                set _bits "${_bits}0"    
            } else {
                set one_bit [random_bit]
                set _bits "${_bits}${one_bit}"
            }
        }
    }

    #--- 
    # select random "num" positions from 0 to _len-1
    #
    public method random_pos { num } {
        #---
        # 1. randomly pick up one bit pos (start from 0) from list
        # 2. remove that pos idx from the list
        # 3. goto 1
        #
        set my_rslt [list]
        set my_list [list]
        for {set i 0} {$i < $_len} {incr i} {
            lappend my_list $i
        }

        set len $_len 
        for {set i 0} {$i < $num} {incr i} {
            set rand_idx [random_idx $len]
            
            lappend my_rslt [lindex $my_list $rand_idx]
            set my_list [lreplace $my_list $rand_idx $rand_idx]
            incr len -1
        }

        return $my_rslt
    }

    #---
    # pick "num" of bits to randomly change their bit value
    #
    public method mutate { {num 1} } {
        set rand_idx [random_pos $num]

        foreach i $rand_idx {
            set rbit [random_bit]
            set _bits [string replace $_bits $i $i $rbit] 
        }
    }

    public method getBits {} {
        return $_bits
    }

    public method setBits { bits } {
        set _bits $bits
        set _len [string length $bits]
    }

    public method getScore {} {
        return $_score
    }

    public method setScore { score } {
        set _score $score
    }

    public method getBitLen {} {
        return [string length $_bits]
    }

    public method clone {} {
        set g ::Genie::[Genie #auto $_len]
        $g setBits $_bits
        $g setScore $_score
        return $g
    }

    public method toString {} {
        return $_bits
    }

    public method dump {} {
        puts $_bits
    }

    public {

        proc random_bit {} {
            if { rand() > 0.5 } {
                return 1
            } else {
                return 0
            }
        }

        proc random_idx { num } {
            return [expr int(rand() * $num)]
        }

        #---
        # randomly create a pair of new genie objects that are created using
        # this 1_cut methodology: 
        #
        proc crossover_1_cut { genie1 genie2 } {
            #---
            # to make sure the cut is in the middle
            #
            set len [$genie1 getBitLen]
            set rand_idx [random_idx [expr $len-1]]


            set bits1 [$genie1 getBits]
            set bits2 [$genie2 getBits]
            set new_bits1 "[string range $bits1 0 $rand_idx][string range $bits2 [expr $rand_idx+1] end]"
            set new_bits2 "[string range $bits2 0 $rand_idx][string range $bits1 [expr $rand_idx+1] end]"

            set newGenie1 ::Genie::[Genie #auto $len]
            set newGenie2 ::Genie::[Genie #auto $len]

            $newGenie1 setBits $new_bits1
            $newGenie2 setBits $new_bits2

            puts "Rich: cut at $rand_idx"
            puts "Rich:   Before $bits1 $bits2"
            puts "Rich:   fter   $new_bits1 $new_bits2"

            return [list $newGenie1 $newGenie2]
        }
    }
}


#---
#
# 1. define bits to multiple functions
# 2. define constraints to bits
#
class GA {

    #--- original GA seetting
    #
    protected variable _pool
    protected variable _glen
    protected variable _constraints
    protected variable _assignments
    protected variable _iteration
    protected variable _ga_pool_size
    protected variable _ga_mutation_bits_ratio
    protected variable _ga_mutation_ratio 

    #--- QA run setup
    protected variable _miptBlock
    protected variable _config
    protected variable _gaconfig
    protected variable _turbo
    protected variable _expId
    protected variable _genie2exp
    protected variable _exp2genie

    constructor  { miptBlock config turbo } {
       
        set _miptBlock $miptBlock
        set _config $config
        set _turbo $turbo
        set _gaconfig [$config getGAConfig]
        set constraints [list]
        set presets [list]

        #--- general setting for ga
        #
        set item0 [lindex $_gaconfig 0]  
        foreach { name value } $item0 {
            set $name $value
        }  

        #--- check the MUST setting
        #
        if { ![info exists ga_pool_size] || 
             ![info exists ga_mutation_bits_ratio] || 
             ![info exists ga_mutation_ratio] } {
            puts "ERROR! Missing general setting: 'ga_pool_size' 'ga_mutation_bits_ratio' 'ga_mutation_ratio'" 
            return -code error
        }
        if { $ga_pool_size < 2 } {
            puts "ERROR! ga pool size is too small" 
            return -code error
        }
        if { $ga_mutation_bits_ratio > 1 || $ga_mutation_bits_ratio < 0 } {
            puts "ERROR! ga mutation bits ratio is invalid, should be 0<= ratio <=1"
            return -code error
        }
        if { $ga_mutation_ratio > 1 || $ga_mutation_ratio < 0 } {
            puts "ERROR! ga crossover ratio is invalid, should be 0<= ratio <=1"
            return -code error
        }

        set _ga_pool_size $ga_pool_size
        set _ga_mutation_bits_ratio $ga_mutation_bits_ratio
        set _ga_mutation_ratio $ga_mutation_ratio

        if { [info exists ga_fit_script] } {
            body GA::ga_fit { qaobj } $ga_fit_script
        }

        if { [info exists ga_stop_script] } {
            body GA::ga_stop {} $ga_stop_script
        }

        #--- remove those user defined functions, keep only variable settings
        #   
        set _gaconfig [lreplace $_gaconfig 0 0]

        set assignments [list]

        #--- ga vars
        #
        array set gavars {}
        set temp_gaConfig {}

        foreach item $_gaconfig {
            set prop_name [lindex $item 0] 
            set range0    [lindex $item 1] 
            set range1    [lindex $item 2] 
            set factor    [lindex $item 3] 
            set samples   [lrange $item 4 end]

            #--- keep the gavar we have processed
            set gavars($prop_name) 1

            puts "Rich sample: $samples"

            #--- Handle the assignments in ga var config section
            #
            if { ![string is double $range0] } {
                if { [info exists gavars($range0)] && $range1 == "" } {
                    #--- skip calculation of range and presets
                    #
                    lappend assignments [list $prop_name $range0]
                    continue
                } else {
                    puts "Cannot find reference $range0 for $prop_name"
                    return -code error
                }
            }

            lappend temp_gaConfig $item

            set converted_samples [list]
            if { $factor > 1 } {
                set range [expr int(($range1 - $range0) * $factor)]
                lappend constraints $range
                foreach sample $samples {
                    if { $sample < $range0 || $sample > $range1 } {
                        puts "Bad config sample points setting for $prop_name , $sample exceeds boundary"
                    }
                    set newVal [expr int($sample * $factor - $range0 * $factor)]
                    lappend converted_samples $newVal
                } 
                if { [llength $converted_samples] > 0 } {
                    lappend presets $converted_samples
                }
                
            } else {
                #---- for those binary setting
                #
                lappend constraints 1
                foreach sample $samples {
                    if { $sample == $range0 } {
                        set newVal 0
                    } elseif { $sample == $range1 } {
                        set newVal 1
                    } else {
                        puts "Bad config sample points setting for $prop_name : $sample "
                        return -code error
                    }
                    lappend converted_samples $newVal
                } 
                if { [llength $converted_samples] > 0 } {
                    lappend presets $converted_samples
                }
            }  
        }


        #-- removed assignemnts
        #
        set _gaconfig $temp_gaConfig
        
        init_ga $_ga_pool_size $constraints $presets $assignments
    }

    #----
    # should be overwrite
    #
    public method ga_fit { qaobj } {

        puts "WARNING: using default fit function!"

        set qapath [$qaobj get_qapath]
        set dir   [glob -type d -nocomplain -directory $qapath -tails *tcb*]
        set qaItemReport [::QAItemReport #auto [$qaobj getName] $dir "${qapath}/$dir"]
        set spDist [$qaItemReport get_spDist]

        #--- TODO, error handling
        #
        if { $spDist == "NA" } {
            return 1000000
        }
        delete object $qaItemReport
        return $spDist
    }


    public method ga_stop {} {

        puts "WARNING: using default fit function!"

        if { $_iteration >= 20 } {
            return 1
        } else {
            return 0
        }
    }


    public method genie_to_exp_setting { genie } {

        set values [decode $genie]
        set result [list]

        if { [llength $values] != [llength $_gaconfig] } {
            puts "Genine has dfferent number of settings than ga_config"
            return -error code
        } else {
            for {set i 0} {$i < [llength $values]} {incr i} {
                set genieVal [lindex $values $i]
                set configItem [lindex $_gaconfig $i]

                set name [lindex $configItem 0]
                set v0 [lindex $configItem 1]
                set v1 [lindex $configItem 2]
                set factor [lindex $configItem 3]

                if { $factor > 1 } {
                    set newVal [expr $v0 + ( double($genieVal) / $factor) ]
                    lappend result [list $name $newVal]
                } else {
                    if { $genieVal == 0 } {
                        lappend result [list $name $v0]
                    } else {
                        lappend result [list $name $v1]
                    }
                }
            }

            #--- handle ga var assignments
            #
            for {set i 0} {$i < [llength $_assignments]} {incr i} {
                set assign [lindex $_assignments $i]
                set name [lindex $assign 0]
                set var  [lindex $assign 1]

                foreach aitem $result {
                    set bname [lindex $aitem 0]
                    set bval  [lindex $aitem 1]

                    if { $var == $bname } {
                        lappend result [list $name $bval]
                        break
                    }
                }
            }
        }
        return $result
    }


    public method add_exp_by_genie { genie } {
      
        incr _expId

        set expSettings [genie_to_exp_setting $genie]
        set expName "exp_${_iteration}_${_expId}"
        set exp [$_config makeExp $expName]

        puts "Rich: add_exp_by_genie  $expName"
        foreach setting $expSettings {
            set name [lindex $setting 0]
            set val  [lindex $setting 1]
            $exp addProp $name $val
            puts "    Rich: $name $val"
        }

        set _exp2genie($expName) [$genie getBits]

        set bits [$genie getBits]
        if { [info exists _genie2exp($bits)] } {
            set done_expName $_genie2exp($bits)

            #-- TODO, try not to use [pwd]
            exec ln -s [pwd]/$done_expName [pwd]/$expName
        } else {
            set _genie2exp($bits) $expName
        }

        return $exp
    }


    public method init_ga { num constraints presets assignments } {

        set _pool [list]
        set _glen 0
        set _constraints $constraints
        set _assignments $assignments
        set _iteration 0
        set _expId 0
        array set _genie2exp {}
        array set _exp2genie {}

        #---
        # calculate the bit number we needed
        #
        set newBitMap [list]
        if { [llength $_constraints] > 0 } {
            foreach len $_constraints {
                set len2 [getPower2BitLen $len]     
                lappend newBitMap $len2
                incr _glen $len2
            }
            set _constraints $newBitMap
            puts "Rich GA::_constraints : $_constraints"
        } else {
            lappend _constraints 8
            set _glen 8
        }


        #--- 
        #  iterate all user-defined setting and create genie based on that
        # 
        set prop_num [llength $presets]
        if { $prop_num > 0 } {
            set preset_num [llength [lindex $presets 0]]

            if { $prop_num != [llength $_constraints] } {
                puts "constraints: $_constraints"
                puts "Preset : $presets"
                puts "Error: GA constraints number does not match to ga item number"
            }
       
            for {set i 0} {$i < $preset_num} {incr i} {
                set bits ""
                for {set j 0} {$j < $prop_num} {incr j} {
                    set len [lindex $_constraints $j]
                    set row [lindex $presets $j] 
                    set val [lindex $row $i]     
                    set bits "${bits}[int2bits $val $len]"
                }
                if { [string length $bits] != $_glen } {
                    puts "Error: bits are not the same $_glen vs [string length $bits]"
                    return -code error
                }

                set g ::GA::[Genie #auto $_glen]
                $g setBits $bits
                lappend _pool $g 
            }
        }

        for {set i [llength $_pool]} {$i < $num} {incr i} {
            set g ::GA::[Genie #auto $_glen]
            $g mutate $_glen
            lappend _pool $g
        }

        puts "Rich $_pool"

    }


    public method getPower2BitLen { num } {
        set bitLen 0
        while { 1 } {
            if { $num > 0 } {
                set num [expr $num >> 1] 
                incr bitLen
            } else {
                return $bitLen
            }
        }
    }


    #----
    # TODO: should source the user defined fit functions
    # define the score function for spice simulation tcb
    #
    public method evaluate_spice { qaobj } {
        set qapath [$qaobj get_qapath]
        set dir   [glob -type d -nocomplain -directory $qapath -tails *tcb*]
        set qaItemReport [::QAItemReport #auto [$qaobj getName] $dir "${qapath}/$dir"]
        set spDist [$qaItemReport get_spDist]

        #--- TODO, error handling
        #
        if { $spDist == "NA" } {
            return 1000000
        }

        return $spDist
    }


    #---- this is to submit all the jobs
    #
    public method evaluate { genieList } {
    
        puts "Rich--- evaluate ---"

        $_config clearExps
        foreach genie $genieList {
            set bits [$genie getBits]
            add_exp_by_genie $genie ; #--- add to _config
        }
        set qas [submit_qa $_miptBlock $_config $_turbo]

        for {set i 0} {$i < [llength $qas]} {incr i} { 
            set aqa [lindex $qas $i]
            set agenie [lindex $genieList $i]
            set score [ga_fit $aqa]
            $agenie setScore $score
            puts "-- [$aqa get_qapath] --"
            puts "   geine : [decode $agenie] : $score"
            puts "   score : $score"
            set settings [genie_to_exp_setting $agenie]
            foreach setting $settings {
                puts "   [lindex $setting 0] [lindex $setting 1]"
            }
            puts "\n\n"
        }

        puts "Rich--- end evaluate ---\n\n\n\n"
    }

    #----
    #
    public method iterate {} {

        set logfp [open "ga_iterate.log" w]

        set bestGenie ""
        set bestScore 0

        #---
        # TODO: better stop criteria
        #
        set _iteration 0

        puts "Rich iteration $_iteration"

        while { ![ga_stop] } {

            set pool_size [llength $_pool]

            #---
            # 0. evaluate the fit functions of all genines
            #    Most time consuming step
            #
            evaluate $_pool

            #---
            # 1. calculate best genie and the sum of all fit function  
            #
            set newPool [list]
            set sum 0
            
            foreach g $_pool {
                set c [$g getScore] 
                set sum [expr $sum + $c]

                if {$c > $bestScore} {
                    set bestScore $c
                    set bestGenie $g
                }
            }

            #--- 2. create a wheel based on score ratio
            #       The higher score genie has more seats in the wheel
            #
            foreach g $_pool {
                set c [$g getScore]
                set count [expr int( 0.5 + $pool_size * $c / $sum)] 
                for {set i 0} {$i<$count} {incr i} {
                    lappend newPool [$g clone]                    
                }
            }
            set _pool $newPool

            #--- 3. crossover
            #
            # randomly pick two genies from the wheel and crossover
            #
            set newPool [list]
            set cnt 0
            while {$cnt < $pool_size} {
                set p1 [expr int(rand() * [llength $_pool])]
                set p2 0
                while { 1 } {
                    set p2 [expr int(rand() * [llength $_pool])]
                    if { $p1 != $p2 } {
                        break
                    }
                }
                set g1 [lindex $_pool $p1]
                set g2 [lindex $_pool $p2]
                set new_glist [Genie::crossover_1_cut $g1 $g2]

                set newPool [concat $newPool $new_glist]
                incr cnt 2
            }

            set _pool $newPool
            set newPool [list]

            #--- 4. mutate
            #
            foreach g $_pool {
                if { rand() > $_ga_mutation_ratio } {
                    $g mutate [expr int([$g getBitLen] * $_ga_mutation_bits_ratio) + 1]
                } 
                lappend newPool $g
            }
            set _pool $newPool

            #--- debug
            #
            foreach g $_pool {
                $g dump
            }
            puts $logfp "Rich --- iteration $_iteration"
            set expName $_genie2exp([$bestGenie getBits])
            puts $logfp "Rich --- Best genie $expName -- [$bestGenie toString]"
            puts $logfp "   [decode $bestGenie]"
            set settings [genie_to_exp_setting $bestGenie]
            foreach setting $settings {
                puts $logfp "   [lindex $setting 0] [lindex $setting 1]"
            }
            flush $logfp
            incr _iteration
        } 

        close $logfp
    }

    public method int2bits { a { len  0 } } {
        
        set bits ""
        while { $a > 0 } {
            set bit [expr $a & 0x1]
            if { $bit == 0 } {
                set bits "0${bits}"
            } else {
                set bits "1${bits}"
            }
            set a [expr $a >> 1]
        }

        #--- append 0s
        set remain [expr $len - [string length $bits]]
        if { $remain > 0 } {
            for {set i 0} { $i < $remain } { incr i } {
                set bits "0${bits}"
            }
        }
       
        return $bits
    }

    public method bits2int { bits } {

        set len [string length $bits]
        set value 0
        for {set i 0} {$i < $len} {incr i} {
            set value [expr $value << 1]
            if { [string index $bits $i] == "1" } {
                incr value
            }
        } 
        return $value
    }

    public method decode { genie } {
        set intList [list]
        set bits [$genie getBits]
       
        set startIdx -1 
        set endIdx   -1
        foreach bitLen $_constraints {
            set startIdx [expr $endIdx + 1] 
            set endIdx [expr $startIdx + $bitLen -1]

            set abits [string range $bits $startIdx $endIdx]
            set value [bits2int $abits]
            lappend intList $value
        }

        return $intList
    }

    public method fit { qarun } {

        set values [decode $genie]
        set x [lindex $values 0]
        set y [lindex $values 1]

        puts "Rich x: $x  y: $y"

        #----
        # find (x - )^2 + (y - 1)^2  min
        #
        # set max [expr pow(2,$_glen)]

        set max 20000
        return [expr  $max - pow(($x - 65), 2)  - pow(($y - 1),2)]
    }



}








proc main { _argc _argv } {
    upvar $_argc argc
    upvar $_argv argv

    array set fc {
        overwrite   0
        config      ""
        mipt        ""
        turbo       2
    }

    parseArgs $argv fc

    if { $fc(mipt) == "" || $fc(config) == "" } {
        helpMsg
    }
    
    #--- test miptParser
    set miptFileName $fc(mipt)
    set tokenizer [::MiptTokenizer #auto $miptFileName]
    $tokenizer process
    set miptParser [::MiptParser #auto [$tokenizer getTokens]]
    set miptBlock [$miptParser parse]

    #--- test configSetting
    set configFileName $fc(config)
    set configSetting [::ConfigSetting #auto $configFileName]
    $configSetting dump

    if { [$configSetting getGAConfig] != "" } {

        set myGA [::GA #auto $miptBlock $configSetting $fc(turbo)]
        $myGA iterate

    } else {

        #---- submit all QAs ----
        #
        set qas [submit_qa $miptBlock $configSetting $fc(turbo)]

        #--- from the first QA run, we get the qa itmes
        set one_qa [lindex $qas 0] 
        set qapath [$one_qa get_qapath]
        set dirs   [glob -type d -nocomplain -directory $qapath -tails *_run]

        #-- for every qa item (ex, core, io, sram, std cell .. etc), collect report from all experiments
        #
        set qaItemReportMgr [::QAItemReportMgr #auto]

        set all_collected_lines [list]
        foreach dir $dirs {
            foreach qarun $qas {
                set qapath [$qarun get_qapath]
                set qaname [$qarun getName]
                set itempath "${qapath}/$dir"

                set qaItemReport [::QAItemReport #auto $qaname $dir $itempath]
                # $qaItemReport print 

                $qaItemReportMgr addItem $qaItemReport
            }
        }

        $qaItemReportMgr genReport
    }

 
}


main argc argv


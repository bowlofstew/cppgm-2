#!/bin/env tclsh

package require Itcl
package require struct::set
catch {namespace import  ::itcl::* }

#--- 
# Take .fs3 and .fs3.out file (optional) to create sumamry
#


#--- parse arguments
# tclsh fs3out.tcl [-cc] [-detail] fs_1.fs3.out
#

class Fs3LayerGroupFile {

    protected variable _layer2groupMap
    protected variable _group2layerMap
    protected variable _groups

    constructor { fn } {
        set fp [open $fn]
        set lines [split [read $fp] "\n"]
        set lineIdx 0
        foreach line $lines {
            incr lineIdx
            set ts [splitLine $line]
            if { [llength $ts] == 0 } {
                continue
            }

            set groupName [lindex $ts 0]

            #--- skip comment
            #
            if { [string range $groupName 0 1] == "//" } {
                continue
            }

            lappend _groups $groupName

            #--- simple parser
            #
            if { [lindex $ts 1] != "=" || [lindex $ts 2] != "{" || [lindex $ts end] != "}" } {
                return -code error "Layer group file parsing error at line : $lineIdx"
            }
             
            set layerNames [lrange $ts 3 end-1]
            foreach layer $layerNames {
                set _layer2groupMap($layer) $groupName
                lappend _group2layerMap($groupName) $layer
            }
        }
        close $fp
    }

    public method getGroup { layerName } {
        if { [info exists _layer2groupMap($layerName)] } {
            return $_layer2groupMap($layerName)
        } else {
            return ""
        }
    }

    public method getGroupsArray {} {
        return [array get _layer2groupMap]
    }

    public method getGroups { } {
        return $_groups
    }



    #---
    # Handmade tokenizer that split space, "{" , "}" , and "="
    #
    private method splitLine { line } {
        set t ""
        set ts [list]
        for {set idx 0} {$idx < [string length $line]} {incr idx} {
            set c [string index $line $idx]

            if { $c == "{" || $c == "}"  || $c == "=" } {
                if { $t != "" } {
                    lappend ts $t
                    set t ""
                }
                lappend ts $c
            } elseif { $c == " "} {
                if { $t != "" } {
                    lappend ts $t
                    set t ""
                }
            } else {
                set t "${t}$c"
            }
        }

        if {$t != ""} {
            lappend ts $t
        }

        return $ts
    }
}


class Fs3File {
    protected variable _lines
    protected variable _id2layer
    protected variable _layer2id

    constructor { fn } {
        set fp [open $fn]
        set _lines [split [read $fp] "\n"]
        close $fp

        array set _id2layer {}
        array set _layer2id {}

        parse 
    }

    private method splitS { line } {
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

    private method makeKey { nid sid } {
        return "${nid}.${sid}"
    }

    private method parse {} {
        foreach line $_lines {
            set ts [splitS $line]
            set firstT [lindex $ts 0]
            if { $firstT == "//" } {
                continue
            }

            set typeStr [string range $firstT 0 3]
            if { $typeStr == "net_" || $typeStr == "via_" || $typeStr == "flr_" } {
                set tmpTs [split $firstT "_"]
                set nid [lindex $tmpTs 1]
                set sid [lindex $ts 1]
                set layer [lindex $ts 6]
                set key [makeKey $nid $sid]
                set _id2layer($key) $layer 
                lappend _layer2id($layer) $key
            }
        }

        #----
        # fs3 does not have ground node "0 0" (but it's in fs3.out).
        # so we just fake one
        #
        set keyGnd [makeKey 0 0]
        set _id2layer($keyGnd) "0"
        lappend _layer2id(0) $keyGnd

    }

    public method getLayers {} {
        return [array names _layer2id]
    }


    public method getLayer { nid sid } {
        set key [makeKey $nid $sid]

        if { [info exists _id2layer($key)] } {
            return $_id2layer($key)
        } else {
            return -code error "Cannot find $nid $sid from fs3 file"
        }
    }


    public method getIds { layerName } {
        
        if {[info exists $_layer2id($layerName)]} {
            return $_layer2id($layerName)
        } else {
            return -code error "Cannot find $layerName from fs3 file"
        }
    }
}


class Fs3Cap {
    protected variable _n1
    protected variable _s1
    protected variable _n2
    protected variable _s2
    protected variable _c

    protected variable _l1
    protected variable _l2

    constructor { n1 s1 n2 s2 cap } {
        set _n1 $n1
        set _s1 $s1
        set _n2 $n2
        set _s2 $s2
        set _c $cap
        set _l1 ""
        set _l2 ""
    }

    public method getC {} {
        return $_c
    }

    public method getN1 {} {
        return $_n1
    }

    public method getS1 {} {
        return $_s1
    }

    public method getN2 {} {
        return $_n2
    }

    public method getS2 {} {
        return $_s2
    }

    public method toString {} {
        return "<$_n1 $_s1 $_n2 $_s2 $_c>"
    }
}



class Fs3OutFile {

    protected variable _capList
    protected variable _id2cap
    protected variable _nid2cap
    
    constructor { fn } {

        set _capList [list]
        array set _id2Cap {}
        array set _nid2Cap {}

        set fp [open $fn]
        while { [gets $fp line]>=0 } {
            set tokens [split $line]
            if { [llength $tokens] < 5 } {
                continue
            }
            set net1 [lindex $tokens 0]  
            set id1  [lindex $tokens 1]
            set net2 [lindex $tokens 2]
            set id2  [lindex $tokens 3]
            set cap  [lindex $tokens 4] 

            set cap [expr $cap * 1e-15]

            set key  [buildKey $net1 $net2]
            if { $net1 != $net2 } {
                set cap [expr -1 * $cap]
            }

            set acap ::Fs3OutFile::[Fs3Cap #auto $net1 $id1 $net2 $id2 $cap]
            lappend _capList $acap
            lappend _id2cap($key) $acap

            #---
            # keep only cc not tc
            # in fs3.out all coupling is duplicate twice
            #
            if { $net1 != $net2 } {
                lappend _nid2cap($net1) $acap
                #---
                # except for "0 0", "0 0" always shows as second netid
                # so we need to collect couplings to "0 0" from each segments
                #
                if { $net2 == 0 } {
                    set acap ::Fs3OutFile::[Fs3Cap #auto 0 0 $net1 $id1 $cap]
                    lappend _nid2cap(0) $acap
                }
            }
        }
        close $fp
    }


    public method getNets {} {
        return [array names _nid2cap]
    }


    public method getTC { nid } {
        set myList $_nid2cap($nid)
        set ctotal 0
        foreach cap $myList {
            set ctotal [expr $ctotal + [$cap getC]]
        }
        return $ctotal
    }

    public method getCC { nid1 nid2 } {
        set myList [getCapObjs $nid1 $nid2]
        set ctotal 0

        if {$nid1 == $nid2} {
            return [getTC $nid1]
        }

        foreach cap $myList {
            set ctotal [expr $ctotal + [$cap getC]]
        }
        return $ctotal
    }

    public method getCapObjs { nid1 {nid2 ""} } {
    
        if { [info exists _nid2cap($nid1)] } {

            if { $nid2 == "" } {
                return $_nid2cap($nid1)
            } else {
                set result [list] 
                foreach cap $_nid2cap($nid1) {
                    if { [$cap getN2] == $nid2 } {
                        lappend result $cap
                    }
                }
                return $result
            }

        } else {
            return [list]
        }
    }


    public method reportTC {} {
        set netIds [lsort [array names _nid2cap]]
        foreach nid $netIds {
            puts "$nid [getTC $nid]"
        }
    }

    public method reportCC {} {
        set netIds [lsort [array names _nid2cap]]
        set len [llength $netIds]

        for { set i 0} {$i < $len} {incr i} {
            for { set j [expr $i + 1]} {$j < $len} {incr j} {
                set nid1 [lindex $netIds $i]
                set nid2 [lindex $netIds $j]

                set myList $_nid2cap($nid1)

                set cc 0
                foreach cap $myList {
                    if { [$cap getN2] == $nid2 } {
                        set cc [expr $cc + [$cap getC]]
                    }
                }

                if {$cc != 0} {
                    puts "${nid1}_________${nid2} $cc"
                }
            }
        }
    }

    private method buildKey { id1  id2 } {
        return "$id1,$id2"
    }
    
    private method splitKey { key } {
        return [split $key ","]
    }
}


proc helpMsg {} {
    puts "Usage:"
    puts "  tclsh fs3out.tcl <file.sp> \[-cc\] \[-fs3 <in.fs3>\]"
    puts "                             \[ -fs3 <in.fs3> \[-tclayer\]\[-tclayer\]\[-group <layer_group>\] \]"
}

proc parseArgs { argList options } {
    upvar 1 $options nv
    
    for {set idx 0} {$idx < [llength $argList]} { incr idx} {
        set arg [lindex $argList $idx]
        switch -exact -- $arg {
            -cc      {   set nv(cc) 1 }
            -cclayer {   set nv(cclayer) 1 }
            -tclayer {   set nv(tclayer) 1 }
            -group   {   
                         incr idx
                         set arg [lindex $argList $idx]
                         set nv(group) $arg

                     }
            -fs3     {
                         incr idx
                         set arg [lindex $argList $idx]
                         set nv(fs3) $arg
                     } 
            -pdb     { 
                         incr idx
                         set arg [lindex $argList $idx]
                         set nv(pdb) $arg 
                     }      
            default  {   
                         if { [string index $arg 0] == "-"} {
                             puts "Unknow option $arg , skip."  
                             helpMsg
                             return -code error
                         }
                         set nv(file) $arg 
                     }
        }
    }
}


proc main { _argc _argv} {
    upvar 1 $_argc argc
    upvar 1 $_argv argv

    array set fc {
        ct        1 
        cc        0
        cclayer   0
        tclayer   0
        group     ""
        pdb       ""
        fs3       ""
    }

    parseArgs $argv fc
    
    if { ![file exists $fc(file)] } {
        helpMsg
        exit 1
    }
    
    set fs3out [Fs3OutFile #auto $fc(file)]

    #---
    # Report total c anyway
    #
    $fs3out reportTC
    if { $fc(cc) != 0 } {
        $fs3out reportCC
    }

    #---
    # Layer decomposition flow
    #
    if { $fc(fs3) != ""} {

        set groupList [list]
        array set layer2groupMap {}

        set fs3 [Fs3File #auto $fc(fs3)]
        if { $fc(group) != "" } {
            set fs3layer [Fs3LayerGroupFile #auto $fc(group)]
            set groupList [$fs3layer getGroups]
            array set layer2groupMap [$fs3layer getGroupsArray]
            #--
            # make sure all layers in the fs3 has a group name
            #
            foreach layer [$fs3 getLayers] {
                if { ![info exists layer2groupMap($layer)] } {
                    lappend groupList $layer
                }
            }
        } else {
            set groupList [$fs3 getLayers]
            foreach layer [$fs3 getLayers] {
                if { ![info exists layer2groupMap($layer)] } {
                    set layer2groupMap($layer) $layer
                }
            }
        }


        #---
        # Total C layer decomposistion report
        #
        if { $fc(tclayer) == 1} {
            foreach nid [$fs3out getNets] {

                #---1. get all couplings related to this net
                #      
                set caps [$fs3out getCapObjs $nid]
                set ct_ori [$fs3out getTC $nid]
                set ct_new 0

                puts [format "%10s%40s %20s %13s" "Net" "Component" "Cap(F)" "Contribution(%)"]
                puts "========================================================="
                #---2. for each group combination, sum related couplings together
                #
                for {set gi1 0} {$gi1 < [llength $groupList]} {incr gi1} {
                    for {set gi2 $gi1} {$gi2 < [llength $groupList]} {incr gi2} {
                        set g1 [lindex $groupList $gi1]
                        set g2 [lindex $groupList $gi2]

                        set cc 0
                        foreach cap $caps {
                            set n1 [$cap getN1] 
                            set n2 [$cap getN2] 
                            set s1 [$cap getS1] 
                            set s2 [$cap getS2] 

                            set l1 [$fs3 getLayer $n1 $s1]
                            set l2 [$fs3 getLayer $n2 $s2]
                            
                            set l1 $layer2groupMap($l1)
                            set l2 $layer2groupMap($l2)

                            if {($l1 == $g1 && $l2 == $g2) || ($l1 == $g2 && $l2 == $g1)} {
                                set cc [expr $cc + [$cap getC]]
                            }
                        }

                        if { $cc != 0} {
                            set ct_new [expr $ct_new + $cc]
                            puts [format "%10s%40s %20E %10.3f" $nid  ${g1}-${g2} $cc [expr 100 * $cc/$ct_ori]]
                        }
                    }
                }  
                puts "-- default ------------ sum ----------- sum -----"
                puts "-- $ct_ori        $ct_new    [expr 100 * $ct_new / $ct_ori]" 
                puts ""
            }
        }

        #---
        # coupling C layer decomposistion report
        #

        if { $fc(cclayer) == 1 } {
            set nids [$fs3out getNets]

            for {set nid1idx 0 } { $nid1idx < [llength $nids] } { incr nid1idx } {
                for {set nid2idx [expr $nid1idx+1] } { $nid2idx < [llength $nids] } { incr nid2idx } {

                    set nid1 [lindex $nids $nid1idx]
                    set nid2 [lindex $nids $nid2idx]

                    #---1. get all couplings related to this net
                    #      
                    set caps [$fs3out getCapObjs $nid1 $nid2]
                    set cc_ori [$fs3out getCC $nid1 $nid2]
                    set cc_new 0

                    if { $cc_ori == 0 } {
                        continue
                    }

                    puts [format "%10s%40s %20s %13s" "Net" "Component" "Cap(F)" "Contribution(%)"]
                    puts "========================================================="
                    #---2. for each group combination, sum related couplings together
                    #
                    for {set gi1 0} {$gi1 < [llength $groupList]} {incr gi1} {
                        for {set gi2 $gi1} {$gi2 < [llength $groupList]} {incr gi2} {
                            set g1 [lindex $groupList $gi1]
                            set g2 [lindex $groupList $gi2]

                            set cc 0
                            foreach cap $caps {
                                set n1 [$cap getN1] 
                                set n2 [$cap getN2] 
                                set s1 [$cap getS1] 
                                set s2 [$cap getS2] 

                                set l1 [$fs3 getLayer $n1 $s1]
                                set l2 [$fs3 getLayer $n2 $s2]
                                
                                set l1 $layer2groupMap($l1)
                                set l2 $layer2groupMap($l2)

                                if {($l1 == $g1 && $l2 == $g2) || ($l1 == $g2 && $l2 == $g1)} {
                                    set cc [expr $cc + [$cap getC]]
                                }
                            }

                            if { $cc != 0} {
                                set tag "${nid1} <-> ${nid2}"
                                set cc_new [expr $cc_new + $cc]
                                puts [format "%10s%40s %20E %10.3f" $tag  ${g1}-${g2} $cc [expr 100 * $cc/$cc_ori]]
                            }
                        }
                    }  
                    puts "-- default ------------ sum ----------- sum -----"
                    puts "-- $cc_ori        $cc_new    [expr 100 * $cc_new / $cc_ori]" 
                    puts ""
                }
            }
        }
    }
}


#--- invoke it
main argc argv


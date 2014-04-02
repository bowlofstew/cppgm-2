package require Itcl

# catch {namespace import  ::itcl::* }

itcl::class Tokenizer {
    protected variable _fname
    protected variable _tokens
    protected variable _splitChars

    constructor { fname } {
        set _fname $fname
        set _tokens [list]
        set _splitChars "*|\"()"
    }

    private method splitS { line {splitChars " "} } {
        set tokens [list]
        set len [string length $line] 
        set prevSplit 0
        set currToken ""
        set t ""
   
        while { $line != "" } {
            if { [regexp {^([\*\|\(\)])} $line t] } {
                lappend tokens $t
            } elseif { [regexp {^("[^"]*")} $line t] } {
                lappend tokens $t
            } elseif { [regexp {^([ \t]+)} $line t] }  {
                # skip space
            } else {
                regexp {^([^ \t"\*\(\)\|]+)} $line t
                lappend tokens $t
            }
            set line [string range $line [string length $t] end]
        }
        return $tokens
    }

    public method setSplit { chars } {
        set _splitChars $chars 
    }

    public method process {} {
        set fp [open $_fname]
        set content [read $fp]
        set lines [split $content "\n"]

        set len [llength $lines] 

        for {set i 0} {$i < $len} {incr i} {
            set tokens [splitS [lindex $lines $i] $_splitChars]
            lappend _tokens $tokens 

            #puts $tokens
        }   
    }

    public method getTokens {} {
        return $_tokens
    }
}


#
# main
#

if {$argc != 1} {
    puts "Expect to see an input file"
    return 1
}

set fname [lindex $argv end]
set tokenizer [::Tokenizer #auto $fname]

$tokenizer process
set tokenLines [$tokenizer getTokens]

foreach tokenLine $tokenLines {
    set line ""
    foreach t $tokenLine {
        set line "$line $t"
    }
    puts $line
}



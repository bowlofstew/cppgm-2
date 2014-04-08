
package require Itcl

catch {namespace import ::itcl::*}


class A {
    method print {} { puts "A::print" }
}

class B {
    variable a
    constructor {} { set a [A #auto] }
    destructor { delete object $a }
    method print {} {
        puts "B::print"
        $a print
    }
}


set b [B #auto]
$b print

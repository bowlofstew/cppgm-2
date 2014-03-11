#!/bin/env tclsh

package require Thread


# tpool::post -nowait $pool_id [list puts "hello"]
#
set program_init {
    variable f;
    proc thread_start { arg0 } {
        set f [open $arg0 w]
        puts $f "child : $arg0"
        puts $f [thread::id]
        # after 2000
    }
}

set program_exit {
    puts $f "chiild [thread::id] exit"
    close $f

}

exec rm -rf 0 1 2

set pool_id [tpool::create -maxworkers 20 -exitcmd $program_exit -initcmd $program_init]

set jids  {}
for {set idx 0} {$idx < 3} {incr idx} {
    # puts "parent : start $idx"
    # set id [tpool::post -nowait $pool_id [list thread_start $idx]]
    # tpool::wait $pool_id $id
    # set tid [tpool::get $pool_id $id]
    # puts $tid
    # puts "parent : end $idx"

    puts "parent : start $idx"
    puts "job : [tpool::post -nowait $pool_id [list thread_start $idx]]"
    puts "names : [tpool::names]"
}

exec cat 0
exec cat 1
exec cat 2







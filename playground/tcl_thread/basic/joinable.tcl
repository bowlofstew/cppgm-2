
package require Thread

set tList [list]
for {set i 0} {$i < 4} {incr i} {
    set tid [thread::create -joinable {
        puts "child thread!" 
        after [expr int(500*rand())]
        puts "child thread end"
    }];
   
    lappend tList $tid
}

puts "main thread"
foreach tid $tList {
    thread::join $tid
}
puts "main end"



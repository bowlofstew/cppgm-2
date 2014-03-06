
package require Thread


thread::create {
    # the script for the thread to run
    set files [glob -directory "/" *]
    puts $files
}

for {set i 0} {$i<30} {incr i} { 
    puts "main thread: $i";
}

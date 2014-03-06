
package require Thread

set tid [thread::create]

thread::send $tid {
    puts "let the child talk for me!";
};


#=== 
#
set mList {1 2 3 4 5}
thread::send $tid [ list set cList $mList ] ; # <- this is reall cool
thread::send $tid { puts "Got list: $cList" }


#=== child thread exception would propogate to main thread 
#
catch {thread::send $tid { expr 2/0 }} retMsg
puts "$retMsg"
puts "$errorInfo"


#=== puts a return variable is pretty much like a catch
#
thread::send $tid { expr acos(10) } retMsg2
puts "$retMsg2"
puts "$errorInfo"







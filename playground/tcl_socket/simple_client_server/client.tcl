#!/bin/env tclsh

set server "localhost"
set port 9900
set sockChannel [socket $server $port]

gets $sockChannel line
close $sockChannel
puts "Time on server is : $line"



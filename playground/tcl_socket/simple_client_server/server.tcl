#!/bin/env tclsh

proc accept_client {channel clientAddr clientPort} {
    puts "connectioin from $clientAddr $clientPort"
    puts $channel [clock format [clock seconds]]
    close $channel
}

socket -server accept_client 9900
vwait forever

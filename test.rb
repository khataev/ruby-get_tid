#!/usr/bin/env ruby

require './thread_info'

puts "Main thread TID: #{Thread.current.tid}"
Thread.new{
    puts "New thread TID: #{Thread.current.tid}"
    puts
    puts `ps axH -o pid,pgid,tid,comm,args -q #{$$}`
}.join

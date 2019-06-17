# Thread#tid

man 2 gettid:

"gettid()  returns  the caller's thread ID (TID).  
In a single-threaded process, the thread ID is equal to the process ID (PID, as returned by getpid(2)).  
In a multithreaded process, all threads have the same PID, but each one has a unique TID."

## Why?

While `Thread.current.object_id` is great for internal thread identification, external tools (eg.: monitors) needs an OS identifier for them, for instance to get the resources stats of a specific thread.

## Compile
```bash
ruby extconf.rb
make
```

## Test

test.rb:
```ruby
require './thread_info'

puts "Main thread TID: #{Thread.current.tid}"
Thread.new{
    puts "New thread TID: #{Thread.current.tid}"
    puts
    puts `ps axH -o pid,pgid,tid,comm,args -q #{$$}`
}.join
```

```bash
tom@vm1:~/ruby-get_tid# ./test.rb
Main thread TID: 29699
New thread TID: 29713

  PID  PGID   TID COMMAND         COMMAND
29699 29699 29699 ruby            ruby test.rb
29699 29699 29712 ruby-timer-thr  ruby test.rb
29699 29699 29713 test.rb:6       ruby test.r
Main proccess PID: 382
```

## TODO

- Portability: currently working only on Linux.
- Turn into a gem.

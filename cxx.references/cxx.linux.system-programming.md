- Linux System Architecture
      
            Linux and the Unix operating system
            The Unix philosophy in a nutshell
            Everything is a process – if it's not a process, it's a file
            One tool to do one task
            Three standard I/O channels
            Word count
            cat
            Combine tools seamlessly
            Plain text preferred
            CLI, not GUI
            Modular, designed to be repurposed by others
            Provide mechanisms, not policies
            Pseudocode
            Linux system architecture
            Preliminaries
            The ABI
            Accessing a register's content via inline assembly
            Accessing a control register's content via inline assembly
            CPU privilege levels
            Privilege levels or rings on the x86
            Linux architecture
            Libraries
            System calls
            Linux – a monolithic OS
            What does that mean?
            Execution contexts within the kernel
            Process context
            Interrupt context

- Virtual Memory
      

            No VM – the problem
            Objective
            Virtual memory
            Addressing 1 – the simplistic flawed approach
            Addressing 2 – paging in brief
            Paging tables – simplified
            Indirection
            Address-translation
            Benefits of using VM
            Process-isolation
            The programmer need not worry about physical memory
            Memory-region protection
            SIDEBAR :: Testing the memcpy() C program
            Process memory layout
            Segments or mappings
            Text segment
            Data segments
            Library segments
            Stack segment
            What is stack memory?
            Why a process stack?
            Peeking at the stack
            Advanced – the VM split

- Resource Limits

            Granularity of resource limits
            Resource types
            Available resource limits
            Hard and soft limits
            Querying and changing resource limit values
            Caveats
            A quick note on the prlimit utility
            Using prlimit(1) – examples
            API interfaces
            Code examples
            Permanence

- Dynamic Memory Allocation

            The glibc malloc(3) API family
            The malloc(3) API
            malloc(3) – some FAQs
            malloc(3) – a quick      
            The free API
            free – a quick      
            The calloc API
            The realloc API
            The realloc(3) – corner cases
            The reallocarray API
            Beyond the basics
            The program break
            Using the sbrk() API
            How malloc(3) really behaves
            Code example – malloc(3) and the program break
            Scenario 1 – default options
            Scenario 2 – showing malloc statistics
            Scenario 3 – large allocations option
            Where does freed memory go?
            Advanced features
            Demand-paging
            Resident or not?
            Locking memory
            Limits and privileges
            Locking all pages
            Memory protection
            Memory protection – a code example
            An Aside – LSM logs, Ftrace
            LSM logs
            Ftrace
            An experiment – running the memprot program on an ARM-32
            Memory protection keys – a brief note
            Using alloca to allocate automatic memory

- Linux Memory Issues

            Common memory issues
            Incorrect memory accesses
            Accessing and/or using uninitialized variables
            Test case 1: Uninitialized memory access
            Out-of-bounds memory accesses
            Test case 2
            Test case 3
            Test case 4
            Test case 5
            Test case 6
            Test case 7
            Use-after-free/Use-after-return bugs
            Test case 8
            Test case 9
            Test case 10
            Leakage
            Test case 11
            Test case 12
            Test case 13
            Test case 13.1
            Test case 13.2
            Test case 13.3
            Undefined behavior
            Fragmentation
            Miscellaneous

- Debugging Tools For Memory Issues

            Tool types
            Valgrind
            Using Valgrind's Memcheck tool
            Valgrind       table
            Valgrind pros and cons : a quick      
            Sanitizer tools
            Sanitizer toolset
            Building programs for use with ASan
            Running the test cases with ASan
            AddressSanitizer (ASan)       table
            AddressSanitizer pros and cons – a quick      
            Glibc mallopt
            Malloc options via the environment
            Some key points
            Code coverage while testing
            What is the modern C/C++ developer to do?
            A mention of the malloc API helpers

- Process Credentials

            The traditional Unix permissions model
            Permissions at the user level
            How the Unix permission model works
            Determining the access category
            Real and effective IDs
            A puzzle – how can a regular user change their password?
            The setuid and setgid special permission bits
            Setting the setuid and setgid bits with chmod
            Hacking attempt 1
            System calls
            Querying the process credentials
            Code example
            Sudo – how it works
            What is a saved-set ID?
            Setting the process credentials
            Hacking attempt 2
            An aside – a script to identify setuid-root and setgid installed programs
            setgid example – wall
            Giving up privileges
            Saved-set UID – a quick demo
            The setres[u|g]id(2) system calls
            Important security notes

- Process Capabilities

            The modern POSIX capabilities model
            Motivation
            POSIX capabilities
            Capabilities – some gory details
            OS support
            Viewing process capabilities via procfs
            Thread capability sets
            File capability sets
            Embedding capabilities into a program binary
            Capability-dumb binaries
            Getcap and similar utilities
            Wireshark – a case in point
            Setting capabilities programmatically
            Miscellaneous
            How ls displays different binaries
            Permission models layering
            Security tips
            FYI – under the hood, at the level of the Kernel

- Process Execution
  
            Process execution
            Converting a program to a process
            The exec Unix axiom
            Key points during an exec operation
            Testing the exec axiom
            Experiment 1 – on the CLI, no frills
            Experiment 2 – on the CLI, again
            The point of no return
            Family time – the exec family APIs
            The wrong way
            Error handling and the exec
            Passing a zero as an argument
            Specifying the name of the successor
            The remaining exec family APIs
            The execlp API
            The execle API
            The execv API
            Exec at the OS level
            Summary table – exec family of APIs
            Code example

- Process Creation

            How fork works
            Using the fork system call
            Fork rule #1
            Fork rule #2 – the return
            Fork rule #3
            Atomic execution?
            Fork rule #4 – data
            Fork rule #5 – racing
            The process and open files
            Fork rule #6 – open files
            Open files and security
            Malloc and the fork
            COW in a nutshell
            Waiting and our simpsh project
            The Unix fork-exec semantic
            The need to wait
            Performing the wait
            Defeating the race after fork
            Putting it together – our simpsh project
            The wait API – details
            The scenarios of wait
            Wait scenario #1
            Wait scenario #2
            Fork bombs and creating more than one child
            Wait scenario #3
            Variations on the wait – APIs
            The waitpid(2)
            The waitid (2)
            The actual system call
            A note on the vfork
            More Unix weirdness
            Orphans
            Zombies
            Fork rule #7
            The rules of fork – a      


- Signaling - Part I

            Why signals?
            The signal mechanism in brief
            Available signals
            The standard or Unix signals
            Handling signals
            Using the sigaction system call to trap signals
            Sidebar – the feature test macros
            The sigaction structure
            Masking signals
            Signal masking with the sigprocmask API
            Querying the signal mask
            Sidebar – signal handling within the OS – polling not interrupts
            Reentrant safety and signalling
            Reentrant functions
            Async-signal-safe functions
            Alternate ways to be safe within a signal handler
            Signal-safe atomic integers
            Powerful sigaction flags
            Zombies not invited
            No zombies! – the classic way
            No zombies! – the modern way
            The SA_NOCLDSTOP flag
            Interrupted system calls and how to fix them with the SA_RESTART
            The once only SA_RESETHAND flag
            To defer or not? Working with SA_NODEFER
            Signal behavior when masked
            Case 1 : Default : SA_NODEFER bit cleared
            Case 2 : SA_NODEFER bit set
            Running of case 1 – SA_NODEFER bit cleared [default]
            Running of case 2 – SA_NODEFER bit set
            Using an alternate signal stack
            Implementation to handle high-volume signals with an alternate signal stack
            Case 1 – very small (100 KB) alternate signal stack
            Case 2 : A large (16 MB) alternate signal stack
            Different approaches to handling signals at high volume

- Signaling - Part II

            Gracefully handling process crashes
            Detailing information with the SA_SIGINFO
            The siginfo_t structure
            Getting system-level details when a process crashes
            Trapping and extracting information from a crash
            Register dumping
            Finding the crash location in source code
            Signaling – caveats and gotchas
            Handling errno gracefully
            What does errno do?
            The errno race
            Fixing the errno race
            Sleeping correctly
            The nanosleep system call
            Real-time signals
            Differences from standard signals
            Real time signals and priority
            Sending signals
            Just kill 'em
            Killing yourself with a raise
            Agent 00 – permission to kill
            Are you there?
            Signaling as IPC
            Crude IPC
            Better IPC – sending a data item
            Sidebar – LTTng
            Alternative signal-handling techniques
            Synchronously waiting for signals
            Pause, please
            Waiting forever or until a signal arrives
            Synchronously blocking for signals via the sigwait* APIs
            The sigwait library API
            The sigwaitinfo and the sigtimedwait system calls
            The signalfd(2) API

- Timers

            Older interfaces
            The good ol' alarm clock
            Alarm API – the downer
            Interval timers
            A simple CLI digital clock
            Obtaining the current time
            Trial runs
            A word on using the profiling timers
            The newer POSIX (interval) timers mechanism
            Typical application workflow
            Creating and using a POSIX (interval) timer
            The arms race – arming and disarming a POSIX timer
            Querying the timer
            Example code snippet showing the workflow
            Figuring the overrun
            POSIX interval timers – example programs
            The reaction – time game
            How fast is fast?
            Our react game – how it works
            React – trial runs
            The react game – code view
            The run:walk interval timer application
            A few trial runs
            The low – level design and code
            Timer lookup via proc
            A quick mention
            Timers via file descriptors
            A quick note on watchdog timers

- Multithreading With Pthreads Part I - Essentials

            Multithreading concepts
            What exactly is a thread?
            Resource sharing
            Multiprocess versus multithreaded
            Example 1 – creation/destruction – process/thread
            The multithreading model
            Example 2 – matrix multiplication – process/thread
            Example 3 – kernel build
            On a VM with 1 GB RAM, two CPU cores and parallelized make -j4
            On a VM with 1 GB RAM, one CPU core and sequential make -j1
            Motivation – why threads?
            Design motivation
            Taking advantage of potential parallelism
            Logical separation
            Overlapping CPU with I/O
            Manager-worker model
            IPC becoming simple(r)
            Performance motivation
            Creation and destruction
            Automatically taking advantage of modern hardware
            Resource sharing
            Context switching
            A brief history of threading
            POSIX threads
            Pthreads and Linux
            Thread management – the essential pthread APIs
            Thread creation
            Termination
            The return of the ghost
            So many ways to die
            How many threads is too many?
            How many threads can you create?
            Code example – creating any number of threads
            How many threads should one create?
            Thread attributes
            Code example – querying the default thread attributes
            Joining
            The thread model join and the process model wait
            Checking for life, timing out
            Join or not?
            Parameter passing
            Passing a structure as a parameter
            Thread parameters – what not to do
            Thread stacks
            Get and set thread stack size
            Stack location
            Stack guards

- Multithreading With Pthreads Part II - Synchronization

            The racing problem
            Concurrency and atomicity
            The pedagogical bank account example
            Critical sections
            Locking concepts
            Is it atomic?
            Dirty reads
            Locking guidelines
            Locking granularity
            Deadlock and its avoidance
            Common deadlock types
            Self deadlock (relock)
            The ABBA deadlock
            Avoiding deadlock
            Using the pthread APIs for synchronization
            The mutex lock
            Seeing the race
            Mutex attributes
            Mutex types
            The robust mutex attribute
            IPC, threads, and the process-shared mutex
            Priority inversion, watchdogs, and Mars
            Priority inversion
            Watchdog timer in brief
            The Mars Pathfinder mission in brief
            Priority inheritance – avoiding priority inversion
            Summary of mutex attribute usage
            Mutex locking – additional variants
            Timing out on a mutex lock attempt
            Busy-waiting (non-blocking variant) for the lock
            The reader-writer mutex lock
            The spinlock variant
            A few more mutex usage guidelines
            Is the mutex locked?
            Condition variables
            No CV – the naive approach
            Using the condition variable
            A simple CV usage demo application
            CV broadcast wakeup

- Multithreading With Pthreads Part III

            Thread safety
            Making code thread-safe
            Reentrant-safe versus thread-safe
            Summary  table – approaches to making functions thread-safe
            Thread safety via mutex locks
            Thread safety via function refactoring
            The standard C library and thread safety
            List of APIs not required to be thread-safe
            Refactoring glibc APIs from foo to foo_r
            Some glibc foo and foo_r APIs
            Thread safety via TLS
            Thread safety via TSD
            Thread cancelation and cleanup
            Canceling a thread
            The thread cancelation framework
            The cancelability state
            The cancelability type
            Canceling a thread – a code example
            Cleaning up at thread exit
            Thread cleanup – code example
            Threads and signaling
            The issue
            The POSIX solution to handling signals on MT
            Code example – handling signals in an MT app
            Threads vs processes – look again
            The multiprocess vs the multithreading model – pros of the MT model
            The multiprocess vs the multithreading model – cons of the MT model
            Pthreads – a few random tips and FAQs
            Pthreads – some FAQs
            Debugging multithreaded (pthreads) applications with GDB

- CPU Scheduling On Linux

            The Linux OS and the POSIX scheduling model
            The Linux process state machine
            The sleep states
            What is real time?
            Types of real time
            Scheduling policies
            Peeking at the scheduling policy and priority
            The nice value
            CPU affinity
            Exploiting Linux's soft real-time capabilities
            Scheduling policy and priority APIs
            Code example – setting a thread scheduling policy and priority
            Soft real-time – additional considerations
            RTL – Linux as an RTOS

- Advanced File I/O

            I/O performance recommendations
            The kernel page cache
            Giving hints to the kernel on file I/O patterns
            Via the posix_fadvise(2) API
            Via the readahead(2) API
            MT app file I/O with the pread, pwrite APIs
            Scatter – gather I/O
            Discontiguous data file – traditional approach
            Discontiguous data file – the SG – I/O approach
            SG – I/O variations
            File I/O via memory mapping
            The Linux I/O code path in brief
            Memory mapping a file for I/O
            File and anonymous mappings
            The mmap advantage
            Code example
            Memory mapping – additional points
            DIO and AIO
            Direct I/O (DIO)
            Asynchronous I/O (AIO)
            I/O technologies – a quick comparison
            Multiplexing or async blocking I/O – a quick note
            I/O – miscellaneous
            Linux's inotify framework
            I/O schedulers
            Ensuring sufficient disk space
            Utilities for I/O monitoring, analysis, and bandwidth control

- Troubleshooting And Best Practices

            Troubleshooting tools
            perf
            Tracing tools
            The Linux proc filesystem
            Best practices
            The empirical approach
            Software engineering wisdom in a nutshell
            Programming
            A programmer&#x2019;s checklist – seven rules
            Better testing
            Using the Linux kernel's control groups

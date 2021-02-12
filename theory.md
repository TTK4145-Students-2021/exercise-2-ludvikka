Exercise 2 - Theory questions
-----------------------------

### What is an atomic operation?
> Atomic operations are instructions that will execute without the possibility of being affected. I.e. no other operations running in other threads or processes can affect the executions of the atomic operation. 

### What is a critical section?
> A critical segment is a segment of code that is accessed by more than one process. This is “critical” because if two prosses try to access shared data at the same time and to something to it, the outcome will be unpredictable. 
### What is the difference between race conditions and data races?
> A race condition is when the interleaving of operations can happen in different orders causing the outcome of the code to be unpredictable. Data races is when two or more prosses try to access a shared variable concurrently, and the result becomes unpredictable because of the processes trying to performer their operations at the same time. 

### What are the differences between semaphores, binary semaphores, and mutexes?
> Semaphores is a mechanism that is used to control access to common resources. A semaphore (counting) holds a number. This is the number of available access “spots” to the resources. If a process accesses the resources the semaphore is decremented. When it is done accessing the semaphore increments. The semaphore cant be less than 0. So the value of the semaphore shows have many more process that can access the resource. A binary semaphore can only hold the value 0 and 1 meaning that only one process can access the resources at the time. 
Mutex is created with at the start of a program. The Mutex locks out other threads from using the resources.  This makes sure that the thread using the resource is the only thread can acquire the Mutex and use the resource. A mutex lock is owned by the thread or process,  the thread unlocks the Mutex when it exits the critical section. This is different from semaphores which have no ownership. 


### What are the differences between channels (in Communicating Sequential Processes, or as used by Go, Rust), mailboxes (in the Actor model, or as used by Erlang, D, Akka), and queues (as used by Python)? 
> Every process has a mailbox in which it can receive messages. The messages are stored in the mailbox until they are “consumed” by the process. 
Channels are similar to mailboxes, but they are by default limited to one element, but they can be buffered so that they can hold more. Channels block if they are full, but mailboxes pass the letters on, but doesn’t accept them. 
Ques are simply a linear data structure that stores items. It can’t be used as a message pass based system. But it can still be used ass communication by multiple threads accessing it. 

### List some advantages of using message passing over lock-based synchronization primitives.
> As a programmer it can be hard to keep track of the locks when you are running many threads. So message passing can often be easier to get right than lock-based synchronization.
A program with Message passing is more scalable sine message passing is asynchronously. This means the sender does not have to block until the receiver acts on the message which makes the program less complicated to scale. 


### List some advantages of using lock-based synchronization primitives over message passing.
> A message passing model can still have nondeterminism due to wrong message timing and order. 
Some programs can be a lot easier. Like the first program in this lecture. 
If the program is wait-free, you can get improved performance and reduce the memory need ass there is less object allocation in the form of new messages.

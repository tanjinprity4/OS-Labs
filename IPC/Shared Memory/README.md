Processes and Shared Memory:

The main function runs as a server. It uses IPC_PRIVATE to request a private shared memory. Since the client is the server’s child process created after the shared memory has been created and attached, the child client process will receive the shared memory in its address space and as a result no shared memory operations are required.

This program asks for a shared memory of ten integers and attaches this shared memory segment to its address space. Pointer ShmPTR points to the shared memory segment. 
Then, this program forks a child process to run function ClientProcess(). Thus, two identical copies of address spaces are created, each of which has a variable ShmPTR whose value is a pointer to the shared memory. As a result, the child process has already known the location of the shared memory segment and does not have to use shmget() and shmat(). 

The parent waits for the completion of the child. For the child, it just retrieves the ten integers, which were stored there by the parent before forking the child, prints them. The wait() system call in the parent will detect this. The child process return those values back to the Parent and print again. Finally, the parent exits.


Output:

Assuming, input is 4,5,6,7,8,9,1,2,3,10

Child: 4,5,6,7,8,9,1,2,3,10

Parent: 4,5,6,7,8,9,1,2,3,10

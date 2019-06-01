# PID-Manager
PID Manager
Operating Systems
Author: 
Brien Hewan-Lowe 
Coding, documentation and output was all completed by me. 

Problem: Modify the previous process simulation program by implementing the use of locks to protect the process identifiers represented by the data structure from race conditions. 

int allocate_map()
The allocate_map function returns an integer and takes in no parameters. This will initialize the array that represents the pids. First it will loop through the array and initialize the values of the pids to 0. The next loop will iterate through the array again and check if any pids were not initialized to 0. If any are found then the function will return -1, otherwise it will return 1. 

int allocate_pid()
The allocate pid function returns an integer and takes in no parameters. This function will find a pid and return its value. First it will loop through the array and check if any have the value of 0. Once one if found it will set its value to 0, and return its value from the function. If none of the pids in the array have a value of 0, then that means that no pids are available and the function will return a -1.

void release_pid(int pid)
The release_pid function is a void function that takes in an integer parameter. This function will release the pid passed in through the function by finding the value in the array and setting its value to 0. 

void threadSimulation()
The threadSimulation function is a void function and takes in no parameters. This function will simulate the process of allocating the pids. First the function will lock the mutex object that is being referenced in the pthread_mutex_lock function, then it will set the pidNumber variable to the return value of the allocate_pid function.  The function then checks to see if any pids are available, if none are available then the function will exit. If one is found then it will allocate it and then release the mutex. The function then sleeps for a period of 0 to 3 seconds. The function then locks the mutex object, release the pid and then unlock the mutex object and return from the function. 

main()
In the main function, I will create a pool of 100 threads and then initialize the mutex lock object. Afterwards, I will allocate the map of pids and check if it was successful. Then I will start the process simulation on the pool of 100 threads. Once that is complete, all unfinished threads will be terminated and the mutex is destroyed. 

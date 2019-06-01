//Brien Hewan-Lowe
//PID Manager

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MIN_PID 300
#define MAX_PID 5000
#define numberOfThreads 100
int pidMap[4700]; //5000 - 300 = 4700 process identifiers

int allocate_map(void);
int allocate_pid(void);
void threadSimulation(int thread);
void release_pid(int pid);

int main()
{
    int threadOfPools[numberOfThreads]; //Create a pool of 100 threads
    srand(time(NULL));
    
    int mapAllocate = allocate_map();
    //Checks to see if allocation of maps is successful, if not
    //the program will exit
    if(mapAllocate == 1)
    {
        printf("Successfully allocated a map of pids\n");
    }
    else
    {
        printf("Failed to allocate a map of pids\n");
    }
    
    for(int i = 0; i < numberOfThreads; i++)
    {
        threadSimulation(threadOfPools[i]);
    }
    
    return 0;
}

void threadSimulation(int thread)
{
    int pidNumber = allocate_pid();
    printf("\nAllocating pid %i", pidNumber);
    sleep(rand() % 3); //Pauses the program for up to 3 seconds
    release_pid(pidNumber);
    
}

int allocate_map(void) //Creates and initializes a data structure for representing pids; returns -1 if
{                      //unsuccessful and 1 if successful
    int i = 0;
    //Initializes pids to 0
    for(i = 0; i < sizeof(pidMap)/sizeof(pidMap[0]); i++)
    {
        pidMap[i] = 0;
    }
    
    //If a pid was not initialized the function will return -1
    for(i = 0; i < sizeof(pidMap)/sizeof(pidMap[0]); i++)
    {
        if(pidMap[i] != 0)
        {
            return -1;
        }
    }
    return 1;
}

int allocate_pid(void) //Allocates and returns a pid; returns -1 if if unable to
{                      //allocate a pid (all pids are in use)
    
    for(int i = 0; i < sizeof(pidMap)/sizeof(pidMap[0]); i++) //Loops through all pids
    {
        if(pidMap[i] == 0) //Check to see if one is available
        {
            pidMap[i] = 1; //If you find one then give it a value of 1
            return i + MIN_PID; //returns pid + 300
        }                       // Ex. pidMap[5] is pid 305
        
    }
    printf("No pids found");
    return -1; //If you cannot find one then return -1
}

void release_pid(int pid) //Releases a pid.
{
    pidMap[pid - MIN_PID] = 0; //Sets the process identifier to 0 (releases it)
    //Ex. If I call release_pid(500) in main, then I want processer identifier 500 to be released
    //So this function would release pidMap[500 - 300] or pidMap[200]
    printf("\nSuccessfully released pid %i ", pid);
    printf("\n");
}




#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>

// #define   MAX_COUNT  200
// #define   RAND_MAX   30

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid, pid2;
//      printf("pid is %d\n", pid);
     pid = fork(); // creates first child
//      printf("pid after fork is %d\n", pid);

     if (pid == 0) {
//        printf("This is the 1st child pid %d", getpid());
//        printf(" with parent %d", getppid());
       ChildProcess();

     } 
     else {
//        printf("In else statement --- pid =/= 0 after first fork.\n");
       pid2 = fork(); //creates second child
       if (pid2 == 0) {
//          printf("In nested if statement --- pid2 =/= 0 after second fork.\n");
         ChildProcess();
       }
       ParentProcess();
     }
       

     int rand30 = getRand();
     int rand10 = sleepRand();
     printf("Your random number is %d\n", rand30);
     printf("Your random number for sleep is %d\n", rand10);
  
  
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= getRand(); i++){
       printf("Child Pid: %d is going to sleep\n", getpid());
       sleep(sleepRand());
       printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
     }
//           printf("   This line is from child, value = %d\n", i);
     exit(0);
     printf("   *** Child process is done ***\n");
  
}

void  ParentProcess(void)
{
     int   i, status;

     for (i = 1; i <= getRand(); i++) {}
//           printf("This line is from parent, value = %d\n", i);
     wait(&status);
     printf("Parent Pid: %d has completed.\n", getpid());
     printf("*** Parent is done ***\n");
}

int getRand()
{
  srand((time(NULL)*3453));
  int randNum = ((rand()%30)+1);
  return randNum;
}

int sleepRand()
{
  srand(time(NULL));
  int sleepNum = ((rand()%10) +1);
  return sleepNum;
}
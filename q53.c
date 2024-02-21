#include<stdio.h>               //  for printf and scanf 
#include<unistd.h>              //  for fork(), getpid(), sleep() & 
getppid() 
#include<sys/types.h>           //  for fork(), getpid() & getppid() 
#include<stdlib.h>              //  for exit() 


// In Orphan Process, child process P4 goes to sleep and whenever the 
sleep time period is completed and P4 comes back for execution it's parent 
has already completed it's execution. So, it will get a garbage parent 
PID, whenever it wants to access it's parents PID as it is a orphan 
process. 
	
// In Zombie Process, the parent process P4 goes to sleep and the child 
process P5 executes before P4 and leaves, and then after the completion of 
sleep time period process P4 executes, so here child process P5 will be 
called zombie process beacuse it has executed before it's parent's 
execution, and for P4 (parent) the process P5 is still visible in it's 
table but it has already completed it's execution. 



int main()
{	
	printf("P1 PID : %d \n", (int) getpid());
	pid_t pid = fork();
	
	if(pid == 0)
	{
		printf("P4 PID : %d P1 PID : %d\n", (int) getpid(), (int) getppid());
		printf("Child process P4 is sleeping \n");
		pid_t pid_1 = fork();
		sleep(5);
		if(pid_1 == 0)
		{
			printf("P5 PID : %d P4 PID : %d \n", (int) getpid(), (int) getppid());
			printf("Zombie process P5's PID : %d \n", (int) getpid());
		}
		else{
			printf("Orphan child process P4's PID : %d \n", (int) getpid());
			printf("P4's New Parent PID : %d \n", (int) getppid());
		}
	}
	else
	{
		pid = fork();
		if(pid == 0)
		{
			printf("P2 PID : %d P1 PID : %d\n", (int) getpid(), (int) getppid());
			pid_t pid_1 = fork();
			if(pid_1 == 0)
			{
				printf("P3 PID : %d P2 PID : %d \n", (int) getpid(), (int) getppid());
				exit(0);
			}
			else
			{
				exit(0);
			}
		}
		else
		{
			exit(0);
		}
	}
	
	return 0;
}



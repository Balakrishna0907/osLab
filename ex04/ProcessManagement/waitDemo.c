#include <stdio.h>
#include <sys/types.h> // pid_t
#include <unistd.h> // fork(), getpid(), sleep()
#include <sys/wait.h> // wait()

int main()
{
	   pid_t pid;
	   pid = fork(); // Create a child process
	   if (pid < 0) // Check process creation failure
	   {
			  printf("Process creation failed\n");
			  return 1;
	   }
	   else if (pid == 0) //Child Process, pid == 0 indicates child execution.
	   {
			  printf("\n--- Child Process Started ---\n");
			  printf("Child Process ID : %d\n", getpid());
			  sleep(3); // Simulate some processing time
			  printf("Child Process Completed\n");
	   }
	   else
	   {
			 //Parent waits for child completion.
			 printf("\n--- Parent Process Started ---\n");
			 printf("Parent is waiting for child process...\n");

			 // wait() suspends parent execution until child process terminates.
			 wait(NULL);
			 printf("Child process completed\n");
			 printf("Parent Process ID : %d\n", getpid());
			 printf("Parent Process Resumed");
	   }
	   return 0;
}

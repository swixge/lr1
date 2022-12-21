#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"

int main(int argc, char * argv[])
{
	int pid = fork();
	if (pid == 0)
	{
		print("p2, pid % d\n", getpid());
	}
	else
	{
		print("p1, pid % d\n", getpid());	
		if(fork() == 0 )
		{
			print("p3, pid % d\n", getpid());
		}
		else 
		{
			if (fork() == 0)
			{
				print("p4, pid % d\n", getpid());
			}
			else 
			{
				if (fork() == 0)
				{
					print("p5, pid % d\n", getpid());
					if(fork() == 0)
					{
						print("p6, pid % d\n", getpid());
					}
				}
				else 
				{
					if (fork() == 0)
					{
						print("p7, pid % d\n", getpid());
					}
					
				}
				
			}
			
		}
	}
	return 0;
}
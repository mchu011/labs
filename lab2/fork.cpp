#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int status;
	int lim = 10000;
	int pidChild1, pidChild2, pidChild3;
	
	pidChild1 = fork();				
	printf("%d \n",pidChild1);
		
	if(pidChild1 == -1)
	{
		perror("There's a problem in fork1");
	}
	else if(pidChild1 == 0)
	{
		for(int i = 0; i < lim; i++)
		{
			printf("A");
		}
		printf("\n");
		exit(0);
	}
	else
	{
		if(waitpid(pidChild1, &status, 0) == -1)
		{
			perror("There's a problem in wait1");
		}

		printf("%d \n", pidChild2);		
		pidChild2 = fork();

		if(pidChild2 == -1)
		{
			perror("There's a problem in fork2");
		}
		else if(pidChild2 == 0)
		{
			for(int i = 0; i < lim; i++)
			{
				printf("B");
			}
			printf("\n");
			exit(0);
		}
		else
		{
			if(waitpid(pidChild2, &status, 0) == -1)
			{
				perror("There's a problem in wait2");
			}

			pidChild3 = fork();
			printf("%d ", pidChild3);
			
			if(pidChild3 == -1)
			{
				perror("There's a problem in fork3");
			}
			else if(pidChild3 == 0)
			{
				for(int i = 0; i < lim; i++)
				{
					printf("C");
				}
				printf("\n");
				exit(0);
			}
			else
			{

				if(waitpid(pidChild3, &status, 0) == -1)
				{
					perror("There's a problem in wait3");
				}

				for(int i = 0; i < lim; i++)
				{
					printf("D");
				}
				printf("\n");
			}
		}
	}


	return 0;
}

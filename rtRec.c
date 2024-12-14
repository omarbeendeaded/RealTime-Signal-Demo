#define _POSIX_C_SOURCE 199309

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>


void handler(int sig, siginfo_t *si, void *ucontext)
{
	// Check the value stored in signal
	switch (si->si_value.sival_int)
	{
		case 0:
			printf("Terminating Process...\n");
			exit(0);
			break;
		case 1:
			printf("Aborting Process...\n");
			abort();
			break;
		default:
			printf("Unkown Command\n");
	}
}

int main(void) 
{

	// Change signal handler for SIGRTMIN
	struct sigaction act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	
	if (sigaction(SIGRTMIN, &act, NULL) == -1)
	{
		perror("sigaction");
		exit(1);
	}


	// Block to wait for signal
	printf("Waiting for signal...\n");
	while(1);
}

#define _POSIX_C_SOURCE 199309

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("Usage: rtSend PID VAL\n");
	}
	
	// Get target program and value to send
	pid_t pid = atoi(argv[1]);
	union sigval sv;	
       	sv.sival_int = atoi(argv[2]);


	// Send signal
	if (sigqueue(pid, SIGRTMIN, sv) == -1) {
		perror("sigqueue");
	}
}

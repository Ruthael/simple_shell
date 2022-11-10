#include <stdio.h>
#include <unistd.h>

/**
 * main - get PID and parent PID
 *
 * Return: Always 0.
 */
int main(void)
{
	int pid, ppid;

	pid = getpid();
	printf("My Process ID is %u\n", pid);
	ppid = getppid();
	printf("My Parent Process ID is %u\n", ppid);
	return (0);
}

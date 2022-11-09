#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
pid_t getppid(void);
int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
	my_pid = getppid();
	printf("Again My pid is %u\n", my_pid);
	return (0);
}


#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 * Return: Always 0
 * getpid - used to retrieve current process ID
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%llu\n", my_pid);
    return (0);
}

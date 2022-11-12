#include <stdio.h>
#include <stdlib.h>
/**
 * main - program prints "$ ", takes input command from user
 * and prints it on the next line.
 * @buff: lineptr
 * Return: 0
 */
int main(void)
{
	char *buff = malloc(1024);
	size_t len = 1024;

	while (1)
	{
		printf("$ ");
		getline(&buff, &len, stdin);
		prinf("%s", buff);
	}
	return (0);
}

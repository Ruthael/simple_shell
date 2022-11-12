#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - splits a string and returns an array of individual words
 * @buff: line pointer, string to be parsed
 * @len: length
 * Return: 0
 */
int main(void)
{
	char *buff = malloc(1024);
	size_t len = 1024;
	char *token;

	while (1)
	{
		printf("$ ");
		getline(&buff, &len, stdin);
		printf("buffer getline: %s", buff);
	}
	// strtok breaks a string into a sequence of zero or nonempty tokens
	token = strtok(buff, " ");
	
	while (token)
	{
		printf("buffer strtok: %s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}



#include "main.h"
/**
 * _strlen - find length of a string
 * @str: string
 * Return: string length
 */
int _strlen(const char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);

	while (str[len] != '\0')
		len++;
	return (len);
}

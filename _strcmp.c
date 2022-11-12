#include "main.h"
/**
 * _strcmp - Compare 2 strings
 * @s1: String 1
 * @s2: String 2
 * Return: 0 if are the same, > 0 if str1 is greater, < 0 if str2 is greater
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
		;
	for (i = 0; s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

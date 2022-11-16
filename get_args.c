#include "main.h"
/**
 * get_args - fill an array with args typed by the user
 * @entry: String with input
 * @args: Array to be filled
 * Return: Length of array
 */
int get_args(char *entry, char **args)
{
	int i = 0;
	char *options, *a = entry, *cmd;

	/* Extract initial command 0 */
	cmd = strtok(entry, "\n\t\r ");
	/* initial cmd stored in args array*/
	args[i] = cmd;
	/* Execute while tokens are present */
	while (a != NULL)
	{
		++i;
		/* store nth argument in parameter*/
		options = strtok(NULL, "\n\t\r ");
		a = options;
		/* store parameter in array of args */
		args[i] = options;
	}
	/* Mark end of array by NULL */
	args[i] = NULL;
	/* Return the length of args[] array*/
	return (i);
}

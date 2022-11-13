#include "main.h"
/**
 * verify_builtin - verify if the input is a built-in or not
 * @args: pointer to the array of user input arguments
 * @exit: exit status
 * Return: 0 if cmd is builtin, else -1
 */
int verify_builtin(char **args, int ext)
{
	char *blts[2] = {"exit","env"	}; /* blts - built ins */
	int i = 0;

	while (i < 2)
	{
		if (_strcmp(args[0], blts[i]) == 0)
			break;
		i++;
	}
	if (i == 2) /* Not builtin */
		return (-1);
	if (_strcmp(blts[i], "exit") == 0)
	{
		free(args[0]);
		exit(ext);
	}
	if (_strcmp(blts[i], "env") == 0)
	{
		if (env_var == NULL)
			return (0);
		write(1, env_var, 1000);
	}
	return (0);
}
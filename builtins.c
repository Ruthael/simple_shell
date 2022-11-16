#include "main.h"
int (*get_builtin(char *command))(char **args);
int shellby_exit(char **args);
int shellby_cd(char **args);
/**
 * get_builtin - match cmd with builtin
 * @command: The command to match
 
 * Return: A function pointer to the corresponding builtin.
 */
int (*get_builtin(char *command))(char **args)
{
	builtin_t funcs[] = {
		{ "exit", shellby_exit },
		{ "env", shellby_env },
		{ "setenv", shellby_setenv },
		{ "unsetenv", shellby_unsetenv },
		{ "cd", shellby_cd },
	/*	{ "alias", shelly_alias },*/
		{ NULL, NULL }
	};
	int i;
	for (i = 0; funcs[i].name; i++)
	{
		if (strcmp(funcs[i].name, command) == 0)
			break;
	}
	return (funcs[i].f);
}
/**
 * shellby_exit - Causes normal process termination
 *                for the shellby shell.
 * @args: An array of arguments containing the exit value.
 *
 * Return: If the given exit value is invalid - 2.
 *         O/w - exits with the given status value.
 *
 * Description: If no exit value is given, the function exits with 0.
 */
int shellby_exit(char **args)
{
	int i = 0, sign = 1;
	unsigned int num = 0;

	if (args[0])
	{
		if (args[1][i] == '-')
		if (args[0][i] == '-')
			sign = -1;

		for (; args[0][i]; i++)
		{

			if (args[0][i] == '-')
				sign *= -1;

			if (args[0][i] >= '0' && args[0][i] <= '9')
				num = (num * 10) + (args[0][i] - '0');
			else
				return (2);
		}
	}

	args -= 1;
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);

int shellby_cd(char **args)
{
	char **dir_info;
	char *oldpwd = NULL, *pwd = NULL;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
		return (-1);

	if (args[0])
	{
		if (*(args[0]) == '-')
			chdir(*(_getenv("OLDPWD")) + 7);
		else
		{
			if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(oldpwd);
				return (2);
			}
		}
	}
	else
		chdir(*(_getenv("HOME")) + 5);
	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);

	dir_info = malloc(sizeof(char *) * 2);
	if (!dir_info)
		return (-1);

	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	if (shellby_setenv(dir_info) == -1)
		return (-1);

	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	if (shellby_setenv(dir_info) == -1)
		return (-1);

	free(oldpwd);
	free(pwd);

	free(dir_info);
	return (0);
}

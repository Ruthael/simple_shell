#include "main.h"
/**
 * verify_path - verify if the 1st command can be executed
 * @args: array of user input
 * Return: 0 for success, -1 file doesn't exist
 */
int verify_path(char **args)
{
	char *gp = NULL; /* global path"/usr/bin:/bin:/usr/games:/usr/local/games"*/
	char *global_dup = NULL;
	char *dir_path = NULL; /* " /usr/bin " */
	char *cmd_path = NULL; /* " /usr/bin/touch "*/
	char *test_cph[121];
	int file_exists = -1, i = 0;

	gp = get_env("PATH");
	if (gp == NULL)
		return (-1);
	global_dup = (_strdup(gp));
	dir_path = strtok(global_dup, ":");
	if (dir_path == NULL)
		return (-1);
	free(gp);
	while (file_exists == -1 && dir_path != NULL)
	{
		cmd_path = cat_cmd(dir_path, args[0]);
		test_cph[i] = cmd_path;
		file_exists = exist(test_cph[i]);
		dir_path = strtok(NULL, ":");
		i++;
	}
	i--;
	free(global_dup);
	free_grid(test_cph, i);
	if (file_exists == 0)
	{
		args[0] = test_cph[i];
		return (0);
	}
	else
	{
		free(test_cph[i]);
		return (-1);
	}
}
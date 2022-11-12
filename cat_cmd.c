#include "main.h"
/**
 * cat_cmd - concatenates an input with paths in global variable PATH
 * @dir_path: directory string to be append with the command
 * @cmd: command to be concatenated with the directory
 * Return: Buffer to concatenated path
 */
char *cat_cmd(char *dir_path, char *cmd)
{
	int i, j = 0;
	int len1, len2;
	char *cmd_path = NULL;

	if (dir_path == NULL || cmd == NULL)
		return (NULL);

	len1 = _strlen(dir_path);
	len2 = _strlen(cmd);
	cmd_path = malloc(len1 + len2 + 2);
	if (cmd_path == NULL)
		return (NULL);
	for (i = 0; dir_path[i] != '\0'; i++)
	{
		cmd_path[i] = dir_path[i];
	}
	if (dir_path[i - 1] != '/')
	{
		cmd_path[i] = '/';
		i++;
	}
	while (cmd[j] != '\0')
	{
		cmd_path[i + j] = cmd[j];
		j++;
	}
	cmd_path[i + j] = '\0';
	return (cmd_path);
}
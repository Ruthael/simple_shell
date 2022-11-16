#include "main.h"
/**
 * exist - verify that file exists
 * @path: file path
 * Return: 0 for file present, -1 for not present
 */
int exist(char *path)
{
	int stats_exit;

	status_exit = (open(path, O_RDONLY));
	if (status_exit != -1)
	{
		close(status_exit);
		return (0);
	}
	else
		return (-1);
}

#include "main.h"
/**
 * exist - verify that file exists
 * @path: file path
 * Return: 0 for file present, -1 for not present
 */
int exist(char *path)
{
	int status;

	status = (open(path, O_RDONLY));
	if (status != -1)
	{
		close(status);
		return (0);
	}
	else
		return (-1);
}

#include "main.h"
/**
 * main - main file of simple_shell
 * Return: 0
 */
int main(void)
{
	ssize_t getline_bytes;
	size_t buff_size = 0;
	char *entry, *args[20];
	int count = 1, file_exists = 0, status_verify, status_builtin, ext;

	entry = NULL;
	printf("($) ");
	getline_bytes = getline(&entry, &buff_size, stdin);
	while (getline_bytes != -1)
	{
		if (*entry != '\n')
		{
			get_args(entry, args);
			if (args[0] != NULL)
			{
				file_exists = exist(args[0]); /*evaluates if files exist*/
				if (file_exists != 0) /* if file exists*/
				{
					status_verify = verify_path(args);
					if (status_verify == 0)
					ext = new_child(args),	free(entry), free(*args);
					else
					{status_builtin = verify_builtin(args, ext);
					if (status_builtin != 0)
						ext = cmd_not_found(args, count), free(entry); }
				}
				else /*if file not found*/
				ext = new_child(args), free(entry);
			}
			else
				free(entry);
		}
		else if (*entry == '\n')
			free(entry);
		entry = NULL, count++, printf("($) ");
		getline_bytes = getline(&entry, &buff_size, stdin);
	}
	final_free(entry);
	return (ext);
}

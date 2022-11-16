#include "main.h"
/**
* cmd_not_found - when a command is not found, it will print error msg
* @args: array of input args typed by the user
* @count: number of times shell has been executed/run
* Return: exit status
*/
int cmd_not_found(char **args, int count)
{
	char *shell_name = "hsh";
	char *shell_exe = "./hsh";

	/**
	* isatty() is a function that returns 1 if the
	* fd - (file descriptor) refers to a terminal
	*/
	if (isatty(STDIN_FILENO))
		write(2, shell_name, 3);
	else
	{
		write(2, shell_exe, 5);
	}
	write(2, ": ", 2);
	print_num(count);
	write(2, ": ", 2);
	write(2, args[0], _strlen(args[0]));
	write(2, ": Not Found\n", 12);
	return (127);
}

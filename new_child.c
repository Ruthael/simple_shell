#include "main.h"
/**
 * new_child - creates a new child process
 * @args: array of inputs by the user
 * Return: 0 on success
 */
int new_child(char **args)
{
	pid_t pid;/* Child process id*/
	int status = 0, status_pro;/* child process status indicator */

	pid = fork();/*create a child process*/
	if (pid == -1)/* fail to create child process */
		printf("FAILED TO CREATE CHILD! \n");
	else if (pid == 0)/* new child process id*/
	{
		status_pro = execve(args[0], args, environ);/* run the command */
		if (status_pro == -1)
		{
			status_pro = 126;
			perror("hsh");
			exit(status_pro);
		} /* end child process */
		exit(0);
	}
	 /* not the child -- father id*/
	else
		/* stop parent process execution until child process terminates */
		wait(&status);
		/**
		* macro queries the child termination status
		* provided by the wait and waitpid functions
		*/
	status_pro = WEXITSTATUS(status);
	/* returns the exit code specified by the child process */
	return (status_pro);
	}

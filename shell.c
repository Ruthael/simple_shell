#include "main.h"

int execute(char **argv);
char **clear_input(char **argv);
/**
 * main - main file of simple_shell
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int ret, hist = 1;
	size_t n, index;
	ssize_t read;
	char *name, *line;

	if (argc != 1)
		return (execute(argv + 1));

	if (!isatty(STDIN_FILENO))
	{
		argv = clear_input(argv);
		while (argv)
		{
			command = argv[0];
			ret = execute(argv);
			for (index = 1; argv[index]; index++)
				free(argv[index]);
			free(argv);
			argv = NULL;
			argv = clear_input(argv);
		}
		free(argv);
		return (0);
	}
	
	line = NULL;
	while (1)
	{
		printf("$ ");
		n = 0;
		read = getline(&line, &n, stdin);
		if (read == -1)
		{
			perror("read failed\n");
			return (1);
		}
		argv = _strtok(line, " ");
		if (!argv)
		{
			free(line);
			perror("Failed to tokenize\n");
			continue;
		}
		command = argv[0];
		ret = execute(argv);

		for (index = 0; argv[index]; index++)
			free(argv[index]);
		free(argv);
		free(line);
		return (0);
	}
	return (ret);
}


int execute(char **argv)
{
	pid_t child_pid;
	int status, flag = 0;
	if (command[0] != '/')

	if (command[0] != '/')
	{
		flag = 1;
		argv[0] = get_location(argv[0]);
		command = get_location(command);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		if (flag)
			free(command);
		perror("Error child:");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(command, argv, NULL) == -1)
			create_error(name, hist, argv[0], 1);
			return (127);
	}
	else
	{
		wait(&status);
	}

	if (flag)
		free(command);
	return (0);
}

char **clear_input(char **argv)
{
	size_t n = 0;
	ssize_t read;
	char *line = NULL;

	read = getline(&line, &n, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}
	argv = _strtok(line, " ");
	
	free(line);
	return (argv);
}
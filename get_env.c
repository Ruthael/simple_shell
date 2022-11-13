#include "main.h"
/**
 * get_env - Get the content of a global variable
 * @global_var: Variable to extract from environ(environment variable)
 * Return: Pointer to the content of a variable, or NULL if fails
 */
char *get_env(char *global_var)
{
	int i = 0;
	const char c[] = "=";
	char *env_tok, *env_dup, *env_tok_dup;

	if (global_var != NULL)
	{
		if (environ == NULL)
			return (NULL);
		env_dup = _strdup(environ[i]);
		while (env_dup != NULL)
		{
			env_tok = strtok(env_dup, c);
			if (_strcmp(env_tok, global_var) == 0)
			{
				env_tok = strtok(NULL, c);
				/**printf("%s\n", token);*/
				env_tok_dup = _strdup(env_tok);
				free(env_dup);
				return (env_tok_dup);
			}
			i++;
			free(env_dup);
			env_dup = _strdup(environ[i]);
		}
	}
	return (NULL);
}

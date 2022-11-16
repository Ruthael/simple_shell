#ifndef _MAIN_H_
#define _MAIN_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;
t/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *get_path_dir(char *path);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

/* Builtins */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);


#endif /* _MAIN_H_ */
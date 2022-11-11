#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

int _strcmp(char *s1, char *s2);
int verify_path(char **args);

int exist(char *pathname);
int new_child(char **args);
int verify_builtin(char **args, int exit);
int cmd_not_found(char **args, int count);

void final_free(char *entry);

#endif /* _MAIN_H_ */

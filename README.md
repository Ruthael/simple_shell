# simple_shell

## Description
*Our simple shell is a simple UNIX command line interpreter that reads arguments or input from user, takes input using stdin, parses the input into an array of strings and finally executes the arguments.

### Compilation
* The shell is compiled by the following:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### TASKS
*0. getppid - Prints PID of parent process ID,
	Parent Process ID doesn't change when program executed repeatedly.
	Echo $$ yields same value as getppid(parent PID)



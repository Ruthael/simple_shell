# simple_shell

## Description
* Our simple shell is a simple UNIX command line interpreter that reads arguments or input from user, takes input using stdin, parses the input into an array of strings and finally executes the arguments.
* Program must have same output as sh (/bin/sh).
* Program must also have same error output.
* Printing an error, argv[0] first argument must be identical to the name of the program.

## Compilation
* The shell is compiled by the following:
```
git clone https://github.com/berhanez/simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Instructions
* After compilation, start program by typing ``` ./hsh ```
* Type in a typical command like ``` ls ``` or ``` cat <filename> ```
* When you are done, simply exit by typing ``` exit ```

### Testing
#### Interactive Mode
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

#### non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## PROJECT TASKS
### (IN FOLDER - /Exercises)
* ``` 0-getppid.c ``` - Prints PID of parent process ID,
	Parent Process ID doesn't change when program executed repeatedly.
	Echo $$ yields same value as getppid(parent PID) because $$ is defined to return the process ID of the parent in a subshell; from the man page under "Special Parameters":
* ``` 1-pid_max ``` - shell script that prints the maximum value a process ID can be.
	Invoked by "cat /proc/sys/kernel/pid_max" in a LINUX terminal.

* ``` 0-av.c ``` - Prints all arguments without using ac
* ``` 1-read_line.c ``` - program prints "$ ", wait for the user to enter a command then prints it on the next line.
	Utilizes getline 
```
man 3 getline
```
*2-command_line_to_av.c - function that splits a string and returns an array of each word of the string.
	Utilizes strtok - to parse string into tokens.
```
man strtok
```


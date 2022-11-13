#include "main.h"
/**
* final_free - free memory for final execution
* @ent: Input typed by the user
*/
void final_free(char *ent)
{
	/* isatty() returns 1 if the fd(file descriptor) refers to a terminal */
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(ent);
	}
	if (!isatty(STDIN_FILENO))
		free(ent);
}

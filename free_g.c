#include "main.h"
/**
 * free_g - free allocated memory used previously
 * @g: pointer to grid
 * @h: Height of the grid
 */
void free_g(char **g, int h)
{
	int i = 0;

	if (g == NULL)
	{
		return;
	}

	while (i < h)
	{
		free(g[i]);
		i++;
	}
}
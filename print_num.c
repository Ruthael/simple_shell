#include "main.h"
/**
* print_num - prints numbers (used to print the error msg
* @num: number to print
* Return: number
*/
int print_num(int num)
{
	unsigned int n;
	int i = 0;

	if (num < 0)
	{
		n = -num;
		i = i + _putchar('-');
	}
	else
	{
		n = num;
	}
	if (n / 10 != '\0')
		i = i + print_num(n / 10);
	i = i + _putchar(n % 10 + '0');
	return (i);
}

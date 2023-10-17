#include "main.h"

/**
 * _puts - print string
 * @str: string
 * Return: void
*/

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - print
 * @c: charecter
 * Return: 1 if succeded
*/

int _putchar(int c)
{
	static int m;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || m >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}

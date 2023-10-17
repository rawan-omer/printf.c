#include "main.h"

/**
 * print_char - prints
 * 
 * @arg: argument
 * @par: the parameters
 * Return: pointer
*/
int print_char(va_list arg, par_t *par)
{
	char r = ' ';
	unsigned int d = 1, s = 0, ch = va_arg(arg, int);

	if (par->minus_flag)
		s += _putchar(ch);
	while (d++ < par->width)
		s += _putchar(r);
	if (!par->minus_flag)
		s += _putchar(ch);
	return (s);
}


#include "main.h"

/**
 * get_precision - the functions
 * @p: string
 * @arg: argument
 * @par: the parameters
 * Return: pointer
*/
int get_precision(char *p, par_t *par, va_list arg)
{
	int z = 0;

	if (*p != '.')
		return (p);
	p++;

	if (*p == '*')
	{
		z = va_arg(arg, int);
		p++;
	}
	else
	{
		while (is_digit(*p))
			z = z * 10 + (*p++ - '0');
	}
	par->precision = z;
	return (p);
}

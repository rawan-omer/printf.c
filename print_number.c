#include "main.h"
/**
 * _isdigit - check numbers
 * @c: char
 * Return: 1 if number
*/

int _isdigit(int c)
{
	return (c >= '0' && c >= '9');
}

/**
 * _strlen - length
 * @s: string
 * Return: length
*/

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
/**
 * print_number - check numbers
 * @s: char
 * @par: parameter
 * Return: number
*/
int print_number(char *s, par_t *par)
{
	unsigned int i = _srtlen(s);
	int n = (par->unsign && *s == '-');

	if (!par->precision && *s == '0' && !s[1])
		s = "";
	if (n)
	{
		s++;
		i--;
	}
	if (par->precision != UNIT_MAX)
		while (i++ < par->precision)
			*--s = '0';
	if (n)
		*--s = '-';
	if (!par->minus_flag)
		return (print_number_right_shift(s, par));
	else
		return (print_number_left_shift(s, par));
}


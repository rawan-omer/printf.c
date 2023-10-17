#include "main.h"
/**
 * print_from_to - the functions
 * @r: begin
 * @s: stoping
 * @e: the exipt
 * Return: pointer
*/
int print_from_to(char *r, char *s, char *e)
{
	int sum = 0;

	while (r <= s)
	{
		if (r != e)
			sum += _putchar(*r);
		r++;
	}
	return (sum);
}
/**
 * print_rev- the functions
 * @arg: argument
 * @par: the parameters
 * Return: pointer
*/
int print_rev(va_list arg, par_t *par)
{
	int l, sum;
	char *s = va_arg(arg, char*);
	(void)par;

	if (s)
	{
		for (l = 0; *s; s++)
			l++;
		s--;
		for (; l > 0; l--, s--)
			sum += _putchar(*s);
	}
	return (sum);
}
/**
 * print_rot13- the functions
 * @arg: argument
 * @par: the parameters
 * Return: pointer
*/
int print_rot13(va_list arg, par_t *par)
{
	int i = 0, x = 0, c = 0;
	char r[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(arg, char *);
	(void)par;

	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			x = a[i] - 65;
			c += _putchar(r[x]);
		}
		else
			c += _putchar(a[i]);
		i++;
	}
	return (c);
}

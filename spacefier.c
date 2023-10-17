#include "main.h"

/**
 * get_space - do the function
 * @s: string
 * Return: the number
*/

int (*get_space(char *s)) (va_list arg, par_t *par)
{
	space_t space[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_adress},
		{"S", print_S},
		{"r", print_reverse},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (space[i].space)
	{
		if (*s == space[i].space[0])
			return (space[i].f);
		i++;
	}
	return (NULL);
}
/**
 * get_print_func - the functions
 * @s: string
 * @arg: argument
 * @par: the parameters
 * Return: number
*/

int get_print_func(char *s, va_list arg, par_t *par)
{
	int (*f)(va_list, par_t *) = get_space(s);

	if (f)
		return (f(arg, par));
	return (0);
}

/**
 * get_flag - the functions
 * @s: string
 * @arg: argument
*/
int get_flag(char *s, par_t *par)
{
	int z = 0;

	switch (*s)
	{
		case '+':
			z = par->plus_flag = 1;
			break;
		case '#'
			z = par->hashtag_flag = 1;
			break;
		case ' '
			z = par->space_flag = 1;
			break;
		case '-'
			z = par->minus_flag = 1;
			break;
		case '0'
			z = par->zero_flag = 1;
			break;
	}
	return (z);
}
/**
 * get_modifier - the functions
 * @s: string
 * @arg: argument
*/
int get_modifier(char *s, par_t *par)
{
	int z = 0;

	switch (*s)
	{
		case 'h':
			z = par->h_modifier = 1;
			break;
		case 'l':
			z = par->l_modifier = 1;
			break;
	}
	return (z);
}
/**
 * get_width - the functions
 * @s: string
 * @arg: argument
 * @par: the parameters
 * Return: pointer
*/
int get_width(char *s, par_t *par, va_list arg)
{
	int z = 0;

	if (*s == '*')
	{
		z = va_arg(arg, int);
		s++;
	}
	else
	{
		while (is_digit(*s))
			z = z * 10 + (*s++ - '0');
	}
	par->width = z;
	return (s);
}

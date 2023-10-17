#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: string
 *
 * Return: integer
*/

int _printf(const char *format, ...)
{
	int s = 0;
	va_list arg;
	char *p, *r;
	par_t par = PARAMS_INT;

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_par(&par, arg);
		if (*p != '%')
		{
			s += _putchar(*p);
			continue;
		}
		r = p;
		p++;
		while (get_flag(p, &par))
			p++;
		p = get_width(p, &par, arg);
		p = get_precision(p, &par, arg);
		if (get_modifier(p, &par))
			p++;
		if (!get_space(p))
			s += print_from_to(r, p,
					par.l_modifier || par.h_modifier ? p - 1 : 0);
		else
			s += get_print_func(p, arg, &par);
	}
	_putchar(BUF_FLUSH);
	va_end(arg);
	return (s);
}

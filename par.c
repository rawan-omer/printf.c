#include "main.h"

/**
 * init_par - reset bufer
 * @par: parameters
 * @arg: argument
 * Return: nothing
*/

void init_par(par_t *par, va_list arg)
{
	par->unsign = 0;
	par->plus_flag = 0;
	par->minus_flag = 0;
	par->zero_flag = 0;
	par->space_flag = 0;
	par->hashtag_flag = 0;
	par->width = 0;
	par->precision = UINT_MAX;
	par->h_modifier = 0;
	par->l_modifier = 0;
	(void)arg;
}

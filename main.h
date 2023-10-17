#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define UPPERCASE 2
#define LAWERCASE 1

/**
 * struct par - parameters
 * @unsign: unsigned int
 * @plus_flag: unsigned int
 * @space_flag: unsigned int
 * @zero_flag: unsigned int
 * @hashtag_flag: unsigned int
 * @minus_flag: unsigned int
 * @h_modifier: unsigned int
 * @l_modifier: unsigned int
 * @width: unsigned int
 * @pre: unsigned int
*/
typedef struct par
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
	unsigned int width;
	unsigned int pre;

} par_t;

/**
 * struct space - structuer
 * @space: spacefier
 * @f: pointer
*/
typedef struct space
{
	char *space;

	int *(f)(va_list arg, par_t *p);

} space_t;


int _puts(char *s);
int _putchar(int c);

int print_char(va_list arg, par_t *p);
int print_int(va_list arg, par_t *p);
int print_string(va_list arg, par_t *p);
int print_percent(va_list arg, par_t *p);



int _printf(const char *format, ...);

#endif

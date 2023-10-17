#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_UPPERCASE 2
#define CONVERT_LAWERCASE 1

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

	int (*f)(va_list, par_t *);

} space_t;


int _puts(char *s);
int _putchar(int c);

int print_char(va_list arg, par_t *par);
int print_int(va_list arg, par_t *par);
int print_string(va_list arg, par_t *par);
int print_percent(va_list arg, par_t *par);
char *convert(long int n, int b, int flag, par_t *par);
int print_unsigned(va_list arg, par_t *par);
int print_adress(va_list arg, par_t *par);
int (*get_space(char *s))(va_list arg, par_t *par);
int get_print_func(char *s, va_list arg, par_t *par);
int get_flag(char *s, par_t *par);
int get_modifier(char *s, par_t *par);
int *get_width(char *s, va_list arg, par_t *par);
int print_hex(va_list arg, par_t *par);
int print_HEX(va_list arg, par_t *par);
int print_binary(va_list arg, par_t *par);
int print_octal(va_list arg, par_t *par);
int print_from_to(char *r, char *s, char *e);
int print_rev(va_list arg, par_t *par);
int print_rot13(va_list arg, par_t *par);
int _isdigit(int c);
int _strlen(int *s);
int print_number(char *s, par_t *par);
void init_par(va_list arg, par_t *par);
int get_precision(char *p, par_t *par, va_list arg);


int _printf(const char *format, ...);

#endif

#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct _flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct _flags
{
	int plus;
	int space;
	int hash;
} _flags_t;

/**
 * struct get_function - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct get_function
{
	char c;
	int (*f)(va_list ap, _flags_t *f);
} get_function_t;

/* print_nums */
int print_int(va_list l, _flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, _flags_t *f);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, _flags_t *f);
int print_hex_big(va_list l, _flags_t *f);
int print_binary(va_list l, _flags_t *f);
int print_octal(va_list l, _flags_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, _flags_t *);

/* get_flag */
int get_flag(char s, _flags_t *f);

/* print_text */
int print_string(va_list l, _flags_t *f);
int print_char(va_list l, _flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, _flags_t *f);
int print_reverse(va_list l, _flags_t *f);
int print_big_string(va_list l, _flags_t *f);

/* print_address */
int print_address(va_list l, _flags_t *f);

/* print_percent */
int print_percent(va_list l, _flags_t *f);

#endif /* MAIN_H */

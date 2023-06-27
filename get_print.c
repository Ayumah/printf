#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, _flags_t *)
{
	get_function_t arr[] = {
	{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'i', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_reverse},
		{'S', print_big_string},
		{'p', print_address},
		{'%', print_percent},
		{"l", print_optional},
		{"h", print_optional}
		};
	int flags = 16;

	register int i;

	for (i = 0; i < flags; i++)
		if (arr[i].c == s)
			return (arr[i].f);
	return (NULL);
}


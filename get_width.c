#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @f: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 *
 * Return: width.
 */

int get_width(va_list list, const char *f, char *i)
{
	int value = 0;

	while ((*f >= '0' && *f <= '9') || (*f == '*'))
	{
		(*i)++;

		if (*f == '*')
		{
			value = va_arg(list, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*f - '0');
		f++;
	}

	return (value);
}

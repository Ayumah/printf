#include "main.h"

/**
 * get_length - Calculates the size to cast the argument
 * @f: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 *
 * Return: Precision
 */
unsigned char get_length(const char *f, char *i)
{
	if (*f == 'h')
	{
		(*i)++;
		return (SHORT);
	}

	else if (*f == 'l')
	{
		(*i)++;
		return (LONG);
	}

	return (0);
}

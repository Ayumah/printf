#include "main.h"

/**
 * get_precision - gets the precision modifier
 * @args: A va_list of arguments.
 * @f: A pointer to a potential precision modifier.
 * @i: An index counter for the original format string.
 *
 * Return: If a precision modifier is matched - its value.
 *         If the precision modifier is empty, zero, or negative - 0.
 *         Otherwise - -1.
 */
int get_precision(va_list list, const char *f, char *i)
{
	int value = 0;

	if (*f != '.')
		return (-1);

	f++;
	(*i)++;

	if ((*f <= '0' || *f > '9') &&
		 *f != '*')
	{
		if (*f == '0')
			(*i)++;
		return (0);
	}

	while ((*f >= '0' && *f <= '9') ||
		   (*f == '*'))
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

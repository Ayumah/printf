#include "main.h"

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexadecimal values need to be lowercase
 * Return: string
 */

char *convert(unsigned long int num, int base, int lowercase)
{
	static char *s;
	static char buffer[50];
	char *ptr;

	s = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = s[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}


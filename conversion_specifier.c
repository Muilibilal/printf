#include "main.h"

/**
 * convert - converts number and base into string
 * @number: input number
 * @base: input base
 * @toLowercase: flag if hexa values need to be lowercase
 * Return: returns a string
 */
char *convert(unsigned long int number, int base, int toLowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (toLowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[number % base];
		number /= base;
	} while (number != 0);

	return (ptr);
}

#include "main.h"


/**
 * _printf - This is a function used to print a formatted output
 *
 * @format: The format in which the argument will be printed
 * @...: Other arguments
 *
 * Return: no. of characters
 */

int _printf(const char *format, ...)
{
	va_list argument_lists;

	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(argument_lists, format);

	while (*format)
	{
		if (*format != '%')
		{
			write_character(*format, &printed_chars);
		}
		else
		{
			fmt_spec_handler(&format, &argument_lists, &printed_chars);
		}

		format++;
	}
	
	return (printed_chars);
}

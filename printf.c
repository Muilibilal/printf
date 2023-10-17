#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - This is a function used to print a formatted output
 *
 * @format: A character string
 * @...: Other arguments
 *
 * Return: 0 success
 */

int _printf(const char *format, ...)
{
	va_list argument_lists;

	int printed_chars = 0;

	if (format == NULL)
		return (1);

	va_start(argument_lists, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				printed_chars++;
			}
			else if (*format == 'c')
			{
				char character = va_arg(argument_lists, int);
				write(1, &character, 1);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(argument_lists, char*);
				int string_length = 0;

				while(string[string_length] != '\0')
					string_length++;

				write(1, string, string_length);
				printed_chars += string_length;
			}
		}

		format++;
	}

	va_end(argument_lists);

	return printed_chars;
}

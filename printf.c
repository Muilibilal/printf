#include "main.h"


/**
 * write_character - function to write character when format specifies c
 *
 * @c: the character we want to write
 * @count: pointer to the count of the printed characters
 *
 * Return: 0 success
 */

static void write_character(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
 * write_string - function to write string when the format specifies s
 *
 * @str: the string we want to write
 * @count: pointer to the count of the printed string
 *
 * Return: 0 success
 */

static void write_string(const char *str, int *count)
{
	int string_length = 0;

	while (str[string_length] != '\0')
		string_length++;

	write(1, str, string_length);
	(*count) += string_length;
}

/**
 * fmt_spec_handler - function to handle the format specified
 *
 * @fmt: pointer to the format specifier
 * @arg_lst: list of arguments
 * @p_chrs: the count of the printed characters
 */

static void fmt_spec_handler(const char **fmt, va_list *arg_lst, int *p_chrs)
{
		(*fmt)++;
		if (**fmt == '\0')
			return;
		if (**fmt == '%')
			write_character(**fmt, p_chrs);
		else if (**fmt == 'c')
		{
			char character = va_arg(*arg_lst, int);

			write_character(character, p_chrs);
		}
		else if (**fmt == 's')
		{
			char *string = va_arg(*arg_lst, char*);

			write_string(string, p_chrs);
		}
}



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
			write_character(*format, &printed_chars);
		}
		else
		{
			fmt_spec_handler(&format, &argument_lists, &printed_chars);
		}

		format++;
	}

	va_end(argument_lists);

	return (printed_chars);
}

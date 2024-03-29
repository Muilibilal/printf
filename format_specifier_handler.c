#include "main.h"

/**
 * fmt_spec_handler - function to handle the format specified
 *
 * @fmt: pointer to the format specifier
 * @arg_lst: list of arguments
 * @p_chrs: the count of the printed characters
 */

void fmt_spec_handler(const char **fmt, va_list *arg_lst, int *p_chrs)
{
	if (**fmt == '%')
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

		else if (**fmt == 'd' || **fmt == 'i')
		{
			int number = va_arg(*arg_lst, int);
			char number_of_chars_in_str[20];

			integer_to_string_converter(number, number_of_chars_in_str);
			write(1, number_of_chars_in_str, strlen(number_of_chars_in_str));
			(*p_chrs) += strlen(number_of_chars_in_str);
		}
	}
}

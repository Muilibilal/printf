#include "main.h"

/**
 * write_string - function to write string when the format specifies s
 *
 * @str: the string we want to write
 * @count: pointer to the count of the printed string
 *
 * Return: 0 success
 */

void write_string(const char *str, int *count)
{
	int string_length = 0;

	while (str[string_length] != '\0')
		string_length++;

	write(1, str, string_length);
	(*count) += string_length;
}

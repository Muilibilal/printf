#include "main.h"


/**
 * integer_to_string_converter - Function to convert the integer to a string
 *
 * @num: The number tp be converted
 * @str: the resulting string
 *
 * Return: stringed integer value
 */

void integer_to_string_converter(int num, char *str)
{
	int leo_i = 0, j;
	int is_leo_integer_negative = 0;
	int length_str;

	if (num < 0)
	{
		is_leo_integer_negative = 1;
		num = -num;
	}

	if (num == 0)
	{
		str[leo_i++] = '0';
	}
	else
	{
		while (num != 0)
		{
			str[leo_i++] = (num % 10) + '0';
			num /= 10;
		}
	}

	if (is_leo_integer_negative)
	{
		str[leo_i++] = '-';
	}

	str[leo_i] = '\0';

	length_str = leo_i;

	for (j = 0; j < length_str / 2; j++)
	{
		char temp = str[j];

		str[j] = str[length_str - j - 1];
		str[length_str - j - 1] = temp;
	}
}

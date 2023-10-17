#include "main.h"

/**
 * write_character - function to write character when format specifies c
 *
 * @c: the character we want to write
 * @count: pointer to the count of the printed characters
 *
 * Return: 0 success
 */

void write_character(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

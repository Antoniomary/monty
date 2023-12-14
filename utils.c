#include "monty.h"

/**
 * is_valid_number - a function that checks if a string is made up of
 * only numbers.
 * @str: the string to check.
 *
 * Return: 1 if true else 0.
 */
int is_valid_number(char *str)
{
	int i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;

	for ( ; str[i] && isdigit(str[i]); ++i)
		;

	return (str[i] == '\0');
}

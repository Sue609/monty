#include "monty.h"


/**
 * is_empty_or_spaces - function that checks for empty line and spaces.
 * @str: a string to be checked.
 *
 * Return: an inte 0 or 1.
 */
int is_empty_or_spaces(const char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))
			return (0);
		str++;
	}

	return (1);
}

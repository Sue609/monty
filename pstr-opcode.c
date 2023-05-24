#include "monty.h"
#include <ctype.h>

/**
 * pstr_stack - function that prints the string
 * starting at the top of the stack.
 * @stack: pointer to the top of the stack.
 * @line_number: converts line number in the monty file
 */

void pstr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0 &&
			 current->n >= 0 && current->n <= 127)
	{
		printf("%c", (char)current->n);
		current = current->next;
	}
	printf("\n");
	(void)line_number;
}


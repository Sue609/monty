#include "monty.h"

/**
 * rot1_stack - This function rotates the stack to the top.
 * @stack: This is a pointer to the top of the stack.
 * @line_number: Current line number in the monty file.
 */

void rot1_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		*stack = first->next;
		(*stack)->prev = NULL;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
	(void)line_number;
}

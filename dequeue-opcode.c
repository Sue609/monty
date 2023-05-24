#include "monty.h"


/**
 * dequeue - A function that removes the top node in a queue.
 * @stack: This is the pointer to the top of the stack.
 * @line_number: Current line number in the monty file.
 */

void dequeue(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty queue\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

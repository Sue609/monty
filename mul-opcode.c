#include "monty.h"

/**
 * mul_stack - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being executed from the monty file.
 */

void mul_stack(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;
	pop_stack(stack, line_number);
	(*stack)->n = result;
}

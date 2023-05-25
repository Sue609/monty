#include "monty.h"


/**
 * sub - A function that subtracts an element from a stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 *
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int a;
	int b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;

	(*stack)->next->n = b - a;
	pop_stack(stack, line_number);
}

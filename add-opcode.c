#include "monty.h"

/**
 * add - Adds the top elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 *
 * Description: If the stack contains less than two elements, prints an error
 * message and exits with EXIT_FAILURE. The result is stored in the second to
 * element of the stack, and the top element is removed, so that at the end:
 * - The top element of the stcak contains the result
 * - The stack is one element shorter.
 */

void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	pop_stack(stack, line_number);
	(*stack)->n = result;
}

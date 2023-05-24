#include "monty.h"


/**
 * swap - function that swaps one element to another.
 * @stack: Pointer to the top of the stack.
 * @line_number: line number of the opcode being executed.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

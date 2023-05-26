#include "monty.h"


/**
 * swap - function that swaps one element to another.
 * @stack: Pointer to the top of the stack.
 * @line_number: line number of the opcode being executed.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;
	stack_t *second = (*stack)->next;
	int temp = first->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first->n = second->n;
	second->n = temp;
}

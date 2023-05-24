#include "monty.h"


/**
 * pint - this function prints the value at the top of the stack.
 * @stack: Double pointer for the top of the code.
 * @line_number: The number of line the opcode should be executed.
 *
 * Return: This function returns nothing.
 */

void pint(stack_t *stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", stack->n);
}

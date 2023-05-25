#include "monty.h"


/**
 * pchar_stack - function that is responsible for printing the character
 * at the topof the stack as per ASII value.
 * @stack: a double poinetr that shows the top of the stack.
 * @line_number: The number of the line to be printed.
 */

void pchar_stack(stack_t **stack, unsigned int line_number)
{
	int value;

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}

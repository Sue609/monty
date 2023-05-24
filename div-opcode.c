#include "monty.h"

/**
 * div_stack - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being executed by the monty file.
 */

void div_stack(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

	(*stack)->n = result;
}

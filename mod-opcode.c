#include "monty.h"


/**
 * mod_stack - function that computes the rest of the division of the 2nd
 * top element by the top element of the stack.
 * @stack: Double pointer of the top of the stack.
 * @line_number: line number being executed from the monty file.
 *
 * Return: nothing.
 */

void mod_stack(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mode, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n % (*stack)->n;
	pop_stack(stack, line_number);
	(*stack)->n = result;
}

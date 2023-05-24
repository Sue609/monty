#include "monty.h"

/**
 * pop_stack - a function that deletes a node from a stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number where the opcode is encountered.
 *
 * Description: The pop_stack function removes the top element form the stack.
 * If stack is empty it prints an error message.
 * pop is an empty stack for the given line number and exits with failure.
 *
 * Return: the function does not return anything.
 */

void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

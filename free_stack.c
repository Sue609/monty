#include "monty.h"


/**
 * free_stack - function that frees the stack and deallocates memory.
 * @stack: The first stack/node.
 * Return: nothing.
 */

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}

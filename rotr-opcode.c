#include "monty.h"


/**
 * rotr_stack - function that rotates the stack to the bottom.
 * @stack: This is the pointer to the top of the stack.
 */

void rotr_stack(stack_t **stack)
{
	stack_t *last = *stack;
	stack_t *second_last = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next =  NULL;
	last->next = *stack;
	*stack = last;
}

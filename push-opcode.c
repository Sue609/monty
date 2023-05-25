#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * push - a function that pushes an element to a stack.
 * @stack: Pointer to the top of the stack.
 * @data: data to the added to the stack.
 *
 * Return: nothing.
 */

void push(stack_t **stack, int data)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = data;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newNode;

	*stack = newNode;
}



/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: Double pointer to the top of the stack.
 */

void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

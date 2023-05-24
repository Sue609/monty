#include "monty.h"

/**
 * enqueue- The opcode queue sets the format of the data to a queue (FIFO).
 * @stack: This is the pointer to the top of the stack.
 * @data: data passed to the function.
 */

void enqueue(stack_t **stack, int data)
{
	stack_t *newNode = create_node(data);
	stack_t *current = *stack;

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (*stack == NULL)
		*stack = newNode;

	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
		newNode->prev = current;
	}
}


/**
 * create_node - A function that creates a node.
 * @data: An integer that is passed to the function
 *
 * Return: a node.
 */

stack_t *create_node(int data)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->next = NULL;

	return (new_node);
}

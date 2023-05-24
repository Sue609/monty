#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * push - a function that pushes an element to a stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: data to the added to the stack.
 * @arg: parameter that represents the arguement passed
 * to the push opcode
 *
 * Return: nothing.
 */

void push(stack_t **stack, const char *arg, unsigned int line_number)
{
	int i;
	int data = atoi(arg);
	stack_t *newNode = malloc(sizeof(stack_t));

	if (arg == NULL || *arg == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; arg[i] != '\0'; i++)
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = data;
	newNode->next = *stack;
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


/**
 * is_number - function that checks if the string is a valid int.
 * @str: string to be checked.
 * Return: 1 or 0.
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; str[i] != '\0'; i++)
	{

		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}



/**
 * add_node - Adds a new node to the stack.
 * @stack: Double pointer to the top of the stack.
 * @data: Data to be stored in the new node.
 * Return: Pointer to the newly added node.
 */

stack_t *add_node(stack_t **stack, int data)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
	return (new_node);
}

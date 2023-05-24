#include "monty.h"


/**
 * free_stack - function that frees the stack and deallocates memory.
 * @stack: The first stack/node.
 * Return: nothing.
 */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *temp;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    *stack = NULL;
}


#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, int data)
{
    stack_t *newNode = malloc(sizeof(stack_t));

    if (newNode == NULL)
    {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    newNode->n = data;
    newNode->prev = NULL;
    newNode->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = newNode;
    }

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

void run_tests()
{
    stack_t *stack = NULL;

    // Test push function
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    // Test pall function
    printf("Stack contents:\n");
    pall(&stack);

    // Test push with non-integer argument
    push(&stack, 50); // Valid push
    push(&stack, atoi("not_an_integer")); // Invalid push

    // Test pall on empty stack
    printf("Empty stack:\n");
    pall(&stack);

    // Free the stack
    free_stack(&stack);
}

int main(void)
{
    run_tests();
    return 0;
}


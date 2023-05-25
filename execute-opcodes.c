#include "monty.h"


/**
 * execute_sub - Function that executes and calls the sub function.
 * @stack: A pointer to the first stack.
 * @line_number: Current line in the monty file.
 */

void execute_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(stack, NULL, line_number, "can't pint, stack empty");
	sub(stack, line_number);
}


/**
 * execute_div - Function that executes and calls the div function.
 * @stack: A pointer to the first stack.
 * @line_number: Current line in the monty file.
 */
void execute_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(stack, NULL, line_number, "can't pint, stack empty");
	div_stack(stack, line_number);
}


/**
 * execute_mul - a function that executes the mul function.
 * @stack: A pointer to the first stack.
 * @line_number: Current line in the monty file.
 */
void execute_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(stack, NULL, line_number, "can't pint, stack empty");
	mul_stack(stack, line_number);
}


/**
 * execute_mod - a function that executes and calls the mod function.
 * @stack: A pointer to the first stack.
 * @line_number: Current line in the monty file.
 */
void execute_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(stack, NULL, line_number, "can't pint, stack empty");
	mod_stack(stack, line_number);
}


/**
 * execute_pchar - function that executes and calls the pchar fucntion.
 * @stack: A pointer to the first stack.
 * @line_number: Current line in the monty file.
 */
void execute_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		handle_error(stack, NULL, line_number, "can't pint, stack empty");
	pchar_stack(stack, line_number);
mod_stack(stack, line_number); }

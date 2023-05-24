#include "monty.h"

/**
 * nop - a function that does nothing.
 * @stack: Double pointer for the top of the stack.
 * @line_number: The opcode being executed.
 *
 * Description: This opcode does not perform any operation. It is used
 * as a placeholder for alignment purposes in the bytecode file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

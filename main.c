#include "monty.h"
#include <string.h>


int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char opcode[100];
	int data;
	unsigned int line_number = 1;
	FILE *file;
	Mode mode = STACK;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}	
	while (fscanf(file, "%s", opcode) != EOF)
	{
		if (strcmp(opcode, "stack") == 0)
			mode = STACK;
		else if (strcmp(opcode, "queue") == 0)
			mode = QUEUE;
		else if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &data) != 1)
			{
				handle_error(&stack, file, line_number, "usage: push integer");
			}
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			if (stack == NULL)
			{
				fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
				fclose(file);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			if (mode == STACK)
				pop_stack(&stack, line_number);
			else if (mode == QUEUE)
				dequeue(&stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
			swap(&stack, line_number);
		else if (strcmp(opcode, "add") == 0)
			add(&stack, line_number);
		else if (strcmp(opcode, "nop") == 0)
			nop(&stack, line_number);
		else if (strcmp(opcode, "sub") == 0)
		{
			if (stack == NULL || stack->next == NULL)
			{
				fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
				fclose(file);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			sub(&stack, line_number);
		}

		else if (strcmp(opcode, "div") == 0)
		{
			if (stack == NULL || stack->next == NULL)
			{
				fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
				fclose(file);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			div_stack(&stack, line_number);
		}
		else if (strcmp(opcode, "mul") == 0)
		{
			if (stack == NULL || stack->next == NULL)
			{
				fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
				fclose(file);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			mul_stack(&stack, line_number);
		}
		else if (strcmp(opcode, "mod") == 0)
		{
			if (stack == NULL || stack->next == NULL)
			{
				fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
				fclose(file);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			mod_stack(&stack, line_number);
		}
		else if (strcmp(opcode, "pchar") == 0)
		{
			if (stack == NULL)
			{
				fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
				fclose(file);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
			pchar_stack(&stack, line_number);
		}
		else if (strcmp(opcode, "pstr") == 0)
			pstr_stack(&stack, line_number);
		else if (strcmp(opcode, "rotl") == 0)
			rot1_stack(&stack, line_number);
		else if (strcmp(opcode, "rotr") == 0)
			rotr_stack(&stack);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	
		line_number++;
	}
	
	fclose(file);
	free_stack(&stack);

	return (0);
}

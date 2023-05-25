#include "monty.h"
#include <string.h>


/**
 * main - The beginning of the code. The main function takes 2 arguements.
 * @argc: Arguement count(no. of arguements passed to the program).
 * @argv: Arguement vector(arguements passes to the program.)
 *
 * Return: 0 success.
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char line[100];
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

	while (fgets(line, sizeof(line), file))
	{
		handle_instruction(&stack, line, line_number, &mode, file);
		line_number++;
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}




void handle_instruction(stack_t **stack, char *line,
		unsigned int line_number, Mode *mode, FILE *file)
{
	char trimmed_line[100], opcode[100], arg[100];
	char *trimmed_ptr = trimmed_line;
	size_t len = strlen(line);
	int data;

	while (isspace(*line))
		line++;
	while (len > 0 && isspace(line[len - 1]))
		line[--len] = '\0';

	strcpy(trimmed_ptr, line);
	if (is_empty_or_spaces(trimmed_line) || trimmed_line[0] == '#')
		return;

	if (sscanf(trimmed_line, "%s", opcode) != 1)
		handle_error(stack, file, line_number, "Invalid opcode");

	if (strcmp(opcode, "stack") == 0)
	{
		*mode = STACK;
		return;
	}

	else if (strcmp(opcode, "queue") == 0)
	{
		*mode = QUEUE;
		return;
	}

	else if (strcmp(opcode, "push") == 0)
	{
		if (sscanf(line, "%*s %[^\n]", arg) != 1)
		{
			printf("Debug: Invalid argument for push instruction\n");
			handle_error(stack, file, line_number, "usage: push integer");
		}
		data = atoi(arg);
		if (*mode == STACK)
			push(stack, data);
		else if (*mode == QUEUE)
			enqueue(stack, data);
		return;
	}
	else
		execute_instruction(stack, opcode, line_number, file, &mode);
}
/**
 * execute_instruction - function that executes the opcode instructions.
 * @stack:  This is the pointer to the top of the stack.
 * @opcode: The code that is converted to monty.
 * @line_number: Current line number in the monty file.
 * @file: character pointer containing a 100 characters in space memory.
 * @mode: A struct that contains the mode either in stack or queue mode.
 *
 * Return: nothing.
 */

void execute_instruction(stack_t **stack, char *opcode,
		unsigned int line_number, FILE *file, Mode **mode)
{
	char arg[100] = "";

	arg[strcspn(arg, " \t\n")] = '\0';

	if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else if (strcmp(opcode, "pint") == 0)
	{
		if (*stack == NULL)
			handle_error(stack, NULL, line_number, "can't pint, stack empty");
		pint(*stack, line_number); }
	else if (strcmp(opcode, "pop") == 0)
	{
		if (**mode == STACK)
			pop_stack(stack, line_number);
		else if (**mode == QUEUE)
			dequeue(stack, line_number); }
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else
	{
		execute_other_instructions(stack, opcode, line_number, file);
	}
}


/**
 * execute_other_instructions - F unction that executes the other opcodes.
 * @stack:  This is the pointer to the top of the stack.
 * @opcode: The code that is converted to monty.
 * @line_number: Current line number in the monty file.
 *  @file: character pointer containing a 100 characters in space memory.
 *
 *  Return: nothing.
 */
void execute_other_instructions(stack_t **stack, char *opcode,
		unsigned int line_number, FILE *file)
{
	if (strcmp(opcode, "sub") == 0)
	/*	execute_sub(stack, line_number);*/
		sub(stack, line_number);

	else if (strcmp(opcode, "div") == 0)
		execute_div(stack, line_number);

	else if (strcmp(opcode, "mul") == 0)
		execute_mul(stack, line_number);

	else if (strcmp(opcode, "mod") == 0)
		execute_mod(stack, line_number);

	else if (strcmp(opcode, "pchar") == 0)
		execute_pchar(stack, line_number);

	else if (strcmp(opcode, "pstr") == 0)
		pstr_stack(stack, line_number);

	else if (strcmp(opcode, "rotl") == 0)
		rot1_stack(stack, line_number);

	else if (strcmp(opcode, "rotr") == 0)
		rotr_stack(stack);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_error - function that handles errors in the opcode
 * @stack: pointer to the first stack.
 * @file: A pointer to the file. Used to handle file-related operations.
 * @line_number: Represents the line number where the error occurred.
 * @error_message: A string containing an error message that
 * describes the specific error that occurred.
 *
 * Return: nothing.
 */
void handle_error(stack_t **stack, FILE *file,
		unsigned int line_number, const char *error_message)
{
	fprintf(stderr, "L%u: %s\n", line_number, error_message);

	if (file != NULL)
		fclose(file);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

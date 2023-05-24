#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void push(stack_t **stack, int data);
void pall(stack_t **stack);
void free_stack(stack_t **stack);
void pint(stack_t *stack, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);
void mod_stack(stack_t **stack, unsigned int line_number);
void pchar_stack(stack_t **stack, unsigned int line_number);
void pstr_stack(stack_t **stack, unsigned int line_number);
void rot1_stack(stack_t **stack, unsigned int line_number);
void rotr_stack(stack_t **stack);

/**
 * Mode - Represents the mode of operation for the stack.
 *
 * Mode enum - The Mode enum is used to specify the mode of operation
 * for the stack.
 * STACK: mode operation.
 * QUEUE: mode operation.
 * Description of the ExampleEnum and its purpose goes here.
 * It can be either STACK or QUEUE.
 */
typedef enum
{
	STACK,
	QUEUE
} Mode;

void dequeue(stack_t **stack, unsigned int line_number);
void enqueue(stack_t **stack, int data);
stack_t *create_node(int data);

void process_opcode(stack_t **stack, char *opcode, int data,
		unsigned int line_number, Mode mode);
void handle_error(stack_t **stack, FILE *file,
		unsigned int line_number, const char *error_message);
void execute_instruction(stack_t **stack, char *opcode,
		unsigned int line_number, FILE *file, Mode mode);


void execute_sub(stack_t **stack, unsigned int line_number);
void execute_div(stack_t **stack, unsigned int line_number);
void execute_mul(stack_t **stack, unsigned int line_number);
void execute_mod(stack_t **stack, unsigned int line_number);
void execute_pchar(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */

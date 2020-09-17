#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_s - structure to store golbal variables of different types
 * @num: string tu convert to int and use it as argument when required
 * @file: file pointer associated with the file opened
 * @mode: mode of working, 0 for stack, 1 for queue
 *
 */
typedef struct global_s
{
	char *num;
	FILE *file;
	int mode;
} global_t;

extern global_t global;

global_t global;

void op_push(stack_t **head, unsigned int line);
void op_pall(stack_t **head, unsigned int line);
void op_pint(stack_t **head, unsigned int line);
void op_pop(stack_t **head, unsigned int line);
void op_swap(stack_t **head, unsigned int line);
void op_add(stack_t **head, unsigned int line);
void op_nop(stack_t **head, unsigned int line);
void op_sub(stack_t **head, unsigned int line);
void op_div(stack_t **head, unsigned int line);
void op_mul(stack_t **head, unsigned int line);
void op_mod(stack_t **head, unsigned int line);
void op_pchar(stack_t **head, unsigned int line);
void op_pstr(stack_t **head, unsigned int line);
void op_rotl(stack_t **head, unsigned int line);
void op_rotr(stack_t **head, unsigned int line);

int set_mode(char *s);
void token_func(char *buffer, char **args);
void (*get_op_func(char *ar))(stack_t **stack, unsigned int line);
int is_number(char *number);
void free_stack(stack_t *head);
size_t stack_len(stack_t *h);

#endif /*_MONTY_H_*/

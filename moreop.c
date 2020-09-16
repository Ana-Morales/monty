#include "monty.h"
/**
 * op_add - adds the top two elements of the stack
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_add where called
 *
 */
void op_add(stack_t **head, unsigned int line)
{
	stack_t *node;

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	node = *head;
	(*head)->next->n = (*head)->n + (*head)->next->n;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	free(node);
}
/**
 * op_nop - doesnt do anything
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_nop where called
 *
 */
void op_nop(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
}
/**
 * op_sub - subtracts the top element of the stack from the second top element
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_sub where called
 *
 */
void op_sub(stack_t **head, unsigned int line)
{
	stack_t *node;

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	node = *head;
	(*head)->next->n = (*head)->next->n - (*head)->n;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	free(node);
}
/**
 * op_div - divides the second top element of the stack by the top element
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_div where called
 *
 */
void op_div(stack_t **head, unsigned int line)
{
	stack_t *node;

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	node = *head;
	(*head)->next->n = (*head)->next->n / (*head)->n;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	free(node);
}
/**
 * op_mul - multiplies the second top element of the stack with the top element
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_mul where called
 *
 */
void op_mul(stack_t **head, unsigned int line)
{
	stack_t *node;

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	node = *head;
	(*head)->next->n = (*head)->next->n * (*head)->n;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	free(node);
}

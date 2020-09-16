#include "monty.h"
/**
 * op_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @head: pointer to the top of the stack
 * @line: line number where op_mod where called
 *
 */
void op_mod(stack_t **head, unsigned int line)
{
	stack_t *node;

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
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
	(*head)->next->n = (*head)->next->n % (*head)->n;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	free(node);
}
/**
 * op_pchar - prints the char at the top of the stack, followed by a new line
 * @head: pointer to the top of the stack
 * @line: line number where op_pchar where called
 *
 */
void op_pchar(stack_t **head, unsigned int line)
{
	int number;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	number = (*head)->n;
	if (number < 0 || number > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	putchar(number);
	putchar('\n');
}
/**
 * op_pstr - prints the string starting at the top of the stack
 * @head: pointer to the top of the stack
 * @line: line number where op_pstr where called
 *
 */
void op_pstr(stack_t **head, unsigned int line)
{
	stack_t *current;
	int number;

	(void)line;
	current = *head;
	if (*head == NULL)
	{
		putchar('\n');
		return;
	}
	while (current != NULL)
	{
		number = current->n;
		if (number <= 0 || number > 127)
			break;
		putchar(number);
		current = current->next;
	}
	putchar('\n');
}
/**
 * op_rotl - rotates the stack to the top
 * @head: pointer to the top of the stack
 * @line: line number where op_rotl where called
 *
 */
void op_rotl(stack_t **head, unsigned int line)
{
	stack_t *current;

	(void)line;
	current = *head;
	if (stack_len(*head) < 2)
		return;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *head;
	current->next->prev = current;
	*head = (*head)->next;
	current->next->next = NULL;
	(*head)->prev = NULL;
}
/**
 * op_rotr - rotates the stack to the bottom.
 * @head: pointer to the top of the stack
 * @line: line number where op_rotr where called
 *
 */
void op_rotr(stack_t **head, unsigned int line)
{
	stack_t *current;

	(void)line;
	current = *head;
	if (stack_len(*head) < 2)
		return;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *head;
	current->prev->next = NULL;
	current->prev = NULL;
	(*head)->prev = current;
	*head = current;
}

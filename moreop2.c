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
 * @line: line number in main function where op_push where called
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
 * @line: line number in main function where op_push where called
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
		{
			putchar('\n');
			return;
		}
		putchar(number);
		current = current->next;
	}
}

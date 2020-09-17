#include "monty.h"
/**
 * op_push - adds a new element to a stack data structure.
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_push where called
 *
 */
void op_push(stack_t **head, unsigned int line)
{	stack_t *new, *temp = *head;
	int n;
	char *ar;

	ar = global.num;
	if (ar == NULL || is_number(ar) == 0)
	{	fprintf(stderr, "L%d: usage: push integer\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	n = atoi(ar);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{	fprintf(stderr, "Error: malloc failed\n");
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{	new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		if (global.mode == 0)
		{	(*head)->prev = new;
			new->next = *head;
			new->prev = NULL;
			*head = new;
		}
		else
		{
			while (temp->next != NULL)
			{	temp = temp->next;	}
			new->next = NULL;
			new->prev = temp;
			temp->next = new;
		}
	}
}
/**
 * op_pall - prints all the elements of a stack data structure
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_pall where called
 *
 */
void op_pall(stack_t **head, unsigned int line)
{
	stack_t *current;
	(void)line;

	current = *head;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * op_pint - prints the value at the top of the stack
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_pint where called
 *
 */
void op_pint(stack_t **head, unsigned int line)
{
	stack_t *current;

	current = *head;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
/**
 * op_pop - removes the top element of the stack.
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_pop where called
 *
 */
void op_pop(stack_t **head, unsigned int line)
{
	stack_t *node;

	node = *head;
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	if (node->next != NULL)
		node->next->prev = NULL;
	*head = (*head)->next;
	free(node);
}
/**
 * op_swap - swaps the top two elements of the stack
 * @head: pointer to the top of the stack
 * @line: line number in main function where op_swap where called
 *
 */
void op_swap(stack_t **head, unsigned int line)
{
	stack_t *temp;

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_stack(*head);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	(*head)->prev = temp;
	(*head)->next = temp->next;
	if ((*head)->next != NULL)
		(*head)->next->prev = *head;
	temp->next = *head;
	temp->prev = NULL;
	*head = temp;
}

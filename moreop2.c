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

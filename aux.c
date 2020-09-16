#include "monty.h"
/**
 * stack_len - returns the number of elements in a stack.
 * @h: points to the top of the stack
 *
 * Return: number of elements.
 */
size_t stack_len(stack_t *h)
{
	stack_t *current = h;
	size_t n = 0;

	while (current != NULL)
	{
		n++;
		current = current->next;
	}
	return (n);
}

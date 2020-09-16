#include "monty.h"
/**
 * get_op_func - selects the correct funct to perform the required op
 * @ar: string to check
 *
 * Return: pointer to the function that corresponds to the string
 * given as a parameter. NULL if no function is found.
 */
void (*get_op_func(char *ar))(stack_t **stack, unsigned int line)
{
	instruction_t op[] = {
		{"push", op_push}, {"pall", op_pall},
		{"pint", op_pint}, {"pop", op_pop}, {"swap", op_swap},
		{"add", op_add}, {"nop", op_nop}, {"sub", op_sub},
		{"div", op_div}, {"mul", op_mul}, {"mod", op_mod},
		{"#", op_nop}, {"pchar", op_pchar}, {"pstr", op_pstr},
		{NULL, NULL},
	};
	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (strcmp(ar, op[i].opcode) == 0)
		{
			return (op[i].f);
		}
		i++;
	}
	return (NULL);
}

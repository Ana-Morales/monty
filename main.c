#include "monty.h"
/**
 * main - main function
 * @argc: argument count
 * @argv: argument values
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char buff[512], *args[100];
	char *err = "unknown instruction";
	stack_t *head = NULL;
	void (*fp)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.file = fopen(argv[1], "r");
	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buff, sizeof(buff), global.file))
	{
		token_func(buff, args);
		if (args[0] == NULL)
			continue;
		global.num = args[1];
		fp = get_op_func(args[0]);
		if (fp == NULL)
		{
			fprintf(stderr, "L%d: %s %s\n", __LINE__, err, args[0]);
			fclose(global.file);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
		fp(&head, __LINE__);
	}
	fclose(global.file);
	free_stack(head);
	return (0);
}

/**
 * token_func - function to call strtok function
 * @buffer: buffer with string to be broke into tokens
 * @args:  array of strings where tokens will be stored
 *
 * Return: pointer to array with tokens
 */
void token_func(char *buffer, char **args)
{
	int i = 0;
	char *token;

	token = strtok(buffer, " \n\t");
	for (i = 0; token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, " \n\t");
	}
	args[i] = NULL;
}
/**
 * is_number - checks if a string only contains number
 * @number: string to be checked
 *
 * Return: 1 is the string is a number, 0 otherwise
 */
int is_number(char *number)
{
	int i = 0;

	if (number[0] == '-')
	{
		i = 1;
	}
	while (number[i] != '\0')
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 * free_stack -  free a dlistint_t list.
 * @head: pointer to first node
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}

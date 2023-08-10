#include "monty.h"
/**
 * push - PUSH an integer onto the stack
 * @stack: ddl pter to start of stack
 * @line_number: script line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");

	if (arg == NULL || !isdigit(arg[0]) && arg[0] != '-')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg); /*Converts valid str rep of int to real int*/

	if (!add_node(stack, n)) /*add int as new node to stack*/
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE); /*if adding node fails print error msg*/
	}

	var.stack_len++; /*increment vars that track len of stack*/
}

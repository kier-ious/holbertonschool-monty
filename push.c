#include "monty.h"
/**
 * push - PUSH an integer onto the stack
 * @stack: ddl pter to start of stack
 * @line_number: script line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp; /* tmp pointer to var */

	tmp = *stack; /* store current head in tmp */
	tmp = malloc(sizeof(stack_t)); /* allocate mem for new node */
	if (tmp == NULL)
		free(tmp);
	tmp->n = line_number; /* assigns value to new node */
	tmp->next = *stack;
	tmp->prev = NULL;

	if ((*stack) != NULL) /*check if head isn't NULL */
	{
		(*stack)->prev = tmp; /* update prev ptr of head */
	}
		(*stack) = tmp; /* update head to point to tmp */
}

#include "monty.h"
/**
 * _isdigit - function that checks for a digit (0 through 9)
 * @c: character to be checked
 * Return: 1 for a character that will be a digit or 0 for any else
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
	return (1);
	}
	return (0);
}

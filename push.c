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

	if (!stack)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
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
 * is_digit - function that checks for #'s in a string
 * @str: string being passed
 * Return: 1 for a character that will be a digit or 0 for any else
 */
int is_digit(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-') /* check for neg sign*/
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);

}

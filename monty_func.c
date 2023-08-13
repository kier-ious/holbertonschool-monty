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
 * pall - starting from the top print all values.
 * @stack: dbl ptr to head of stack
 * @line_number: line # opcode is on
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *counter;

	counter = *stack;

	while (counter != NULL)
	{
		printf("%d\n", counter->n); /*print value stored in current node*/
		counter = counter->next; /*move to next node in the list*/
	}
}
#include "monty.h"
/**
 * pint - printing top node
 * @stack: ptr to list
 * @line_number: current line # of monty
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *counter;

	counter = *stack;
	if (counter == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", counter->n);
}
#include "monty.h"
/**
 * pop - Remove top element from the stack
 * @stack: ptr to first node
 * @line_number: current line # in monty file
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;

	if ((*stack) != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(tmp);
}
/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

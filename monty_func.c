#include "monty.h"
int push_arg;
/**
 * check_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * Return: 0 on success -1 on failure
 */
char *check_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *arg;
	(void)stack;

	op_code = strtok(line, WHITESPACE);
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, "push") == 0)
	{
		arg = strtok(NULL, WHITESPACE);
		if (is_a_digit(arg) == 0 && arg != NULL)
		{
			push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
/**
 * push - PUSH an integer onto the stack
 * @stack: ddl pter to start of stack
 * @line_number: script line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node; /* tmp pointer to var */
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = push_arg; /* assigns value to new node */
	new_node->next = *stack;
	new_node->prev = NULL;

	if ((*stack) != NULL) /*check if head isn't NULL */
	{
		(*stack)->prev = new_node; /* update prev ptr of head */
	}
		(*stack) = new_node; /* update head to point to tmp */

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
	stack_t *traverse;

	traverse = *stack;

	while (traverse != NULL)
	{
		printf("%d\n", traverse->n); /*print value stored in current node*/
		traverse = traverse->next; /*move to next node in the list*/
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
	stack_t *traverse;

	traverse = *stack;
	if (traverse == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", traverse->n);
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

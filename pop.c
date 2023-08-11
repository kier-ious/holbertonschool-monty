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
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
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

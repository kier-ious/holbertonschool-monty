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

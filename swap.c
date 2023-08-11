#include "monty.h"
/**
 * swap - Swaps the top elements
 * @stack: opcode in list
 * @line_number: current line # of monty
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *counter;
	int tmp;

	counter = *stack;
	if (counter == NULL || counter->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = counter->n;
	counter->n = counter->next->n;
	counter->next->n = tmp;

}

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

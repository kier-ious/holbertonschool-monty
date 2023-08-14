#include "monty.h"
/**
 * swap - Swaps the top elements
 * @stack: opcode in list
 * @line_number: current line # of monty
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tracker;
	int tmp;

	tracker = *stack;
	if (tracker == NULL || tracker->next == NULL)
	{
		dprintf(STDOUT_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = tracker->n;
	tracker->n = tracker->next->n;
	tracker->next->n = tmp;

}
#include "monty.h"
/**
 * add - adds the top two nodes of stack
 * @stack: opcode
 * @line_number: current line # of monty
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		dprintf(STDOUT_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		dprintf(STDOUT_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
		sum = (*stack)->next->n + (*stack)->n;
		pop(stack, line_number);

	(*stack)->n = sum;
}
#include "monty.h"
/**
 * nop - does nothing
 * @stack: void
 * @line_number: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
#include "monty.h"
/**
 * free_stack_t - frees a dlistint_t list
 *
 * @head: head node
 */
void free_stack_t(stack_t *head)
{
	stack_t *current;
	stack_t *tmp;

	current = head;

	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;

	}
}

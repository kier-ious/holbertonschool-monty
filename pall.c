#include "mont.h"
/**
 * pall - starting from the top print all values.
 * @stack: dbl ptr to head of stack
 * @line_number: being executed from the script file
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_numer); /*unused parameter, cast to avoid issues*/

	head = *stack; /*assign value of dbl pter to head*/

	while (head != NULL)
	{
		printf("%d\n", head->n); /*print value of current node*/

		head = head->next;


		if (head == *stack) /*if end has been reached*/
					/*exit loop*/
		{
			return;
		}
	}
}

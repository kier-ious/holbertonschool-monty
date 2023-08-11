#include "monty.h"
/**
 * monty_op - checks opcode and returns
 * @s: function
 * Return: void
*/
void (*monty_op(char *s))(stack_t **stack, unsigned int)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i;

	i = 0;
	/* iterate over ops array */
	while (instruction[i].opcode != NULL && *(instruction[i].opcode) != *s)
	{
		i++;
	}
	return (instruction[i].f);
}

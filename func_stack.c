#include "monty.h"
/**
 *  * _isdigit - function that checks for a digit (0 through 9)
 * @c: character to be checked
 * Return: 1 for a character that will be a digit or 0 for any else
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

#include "monty.h"
#include <ctype.h>
/**
 * is_a_digit - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int is_a_digit(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
#include "monty.h"
/**
 * check_line - appending the strings
 * @line: line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the line # in which opcide appears
 * Return: 0 on success
 */
int check_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *arg;

	(void)stack;

	op_code = strtok(line, WHITESPACE);
	if (op_code == NULL)
		return (0);

	if (strcmp(op_code, "push") == 0)
	{
		arg = strtok(NULL, WHITESPACE);
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		if (is_a_digit(arg))
		{
			/*int push_arg = atoi(arg);*/
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
		}
	}
	return (0);
}
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

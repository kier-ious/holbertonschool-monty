#include "monty.h"
/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack)
{
	FILE *fp;
	size_t len = 50;
	int num_chars = 0;
	unsigned int line_count = 1;
	/*char *line;*/
	void (*f)(stack_t **stack, unsigned int line_number);

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	char *line = malloc(sizeof(char) * 50);

	while ((num_chars = getline(&line, &len, fp)) != -1)
	{
		line = check_line(line, stack, line_count);
		if (line == NULL)
		{
			line_count++;
			continue;
		}
		f = monty_op(line);
		if (f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		f(stack, line_count);
		line_count++;
	}
	free(line);
	fclose(fp);
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
	while (instruction[i].opcode != NULL && strcmp(instruction[i].opcode, s) != 0)
	{
		i++;
	}
	return (instruction[i].f);
}
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
		{
			return (0);
			i++;
		}
	}
	return (1);
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

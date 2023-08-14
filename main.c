#include "monty.h"
/**
 * main - driver func for main monty
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
*/
int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;

	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1], &stack);
	free_dlistint(stack);
	return (0);
}

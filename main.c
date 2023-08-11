#include "monty.h"
/**
 * main - driver func for main monty
 * @argc: int # of args
 * @argv: opcode file
 * Return: 0
*/
int main(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		monty_op(line);
	}
	free(line);
	fclose(fp);
	return (0);
}

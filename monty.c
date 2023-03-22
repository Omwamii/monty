#include "monty.h"

/**
 * main - entry point
 * @argc: args count
 * @argv: array of arguments
 *
 * Return: success value
 */
stack_t *stack = NULL;
int main(int argc, char **argv)
{
	FILE *fp;
	char *buffer, *opcode = NULL;
	size_t line_len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &line_len, fp) != -1)
	{
		line_number++;
		opcode = strtok(buffer, " \n");
		if (!opcode || *opcode == '#') /* comments & blanks */
			continue;
		else
			execute_opcode(opcode, &stack, line_number);
	}
	free(buffer);
	fclose(fp);
	return (0);

}

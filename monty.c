#include "monty.h"

/**
 * main - entry point
 * @argc: args count
 * @argv: array of arguments
 *
 * Return: success value
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *buffer, *opcode = NULL;
	size_t line_len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

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
		if (strcmp(opcode, "stack") == 0)
			continue;
		if (strcmp(opcode, "queue") == 0)
			queue(&stack, fp, line_number);
		else
			execute_opcode(opcode, &stack, line_number);
	}
	free(buffer);
	fclose(fp);
	return (0);

}

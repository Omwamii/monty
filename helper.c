#include "monty.h"

/**
 * check_handler - checks handler of an opcode
 * @op: opcode to check
 *
 * Return: function pointer to handler function
 */

void (*check_handler(char *op))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{NULL, NULL}
	};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
/**
 * execute_opcode - executes opcode based on function
 * @opcode: opcode to be executed
 * @stack: stack passed
 * @line_number: current position at bytecode file
 *
 * Return: success value
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	f = check_handler(opcode);
	if (f == NULL)
	{
		fprintf(stderr, "L<%u>: unknown instruction <%s>\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	f(stack, line_number); /* call handler fn */
}

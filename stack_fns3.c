#include "monty.h"

/**
 * pchar - prints char at the top of stack
 * @stack: ptr to top stack element
 * @line_number: current file position
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L<%u>: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top->n < 0 || top->n > 127)
	{
		fprintf(stderr, "L<%u>: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}

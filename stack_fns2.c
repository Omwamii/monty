#include "monty.h"

/**
 * add - adds the top two elements of stack
 * @stack: ptr to top element in stack
 * @line_number: current position in bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	int value;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L<%u>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = value;
	pop(stack, line_number);
}

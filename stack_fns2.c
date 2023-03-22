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

/**
 * sub - subtracts top element of the stack from the second top element
 * @stack: ptr to top elemet of stack
 * @line_number: current file position
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int value;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L<%u>: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = value;
	pop(stack, line_number);
}

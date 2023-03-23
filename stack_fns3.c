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

/**
 * pstr - prints string in stack
 * @stack: ptr to top of stack
 * @line_number: current file position
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
		printf("\n");
	else
	{
		while (tmp && (tmp->n >= 0 && tmp->n <= 127) && tmp->n != 0)
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

/**
 * rotl - makes top element becomes last and second top element becomes first
 * @stack: ptr to top of stack
 * @line_number: current file position
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *second = (*stack)->next;
	stack_t *tmp = *stack;

	if (*stack == NULL);
	else
	{
		if (second == NULL); /* only one element in stack */
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = *stack;
			(*stack)->prev = tmp;
			(*stack)->next = NULL;
			*stack = second;
		}
	}
}

/**
 * rotr - makes last element of the stack the top element
 * @stack: ptr to top of stack
 * @line_number: current file position
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL);
	else
	{
		if (tmp->next == NULL); /* only one element in stack */
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->prev->next = NULL;
			tmp->prev = NULL;
			tmp->next = *stack;
			(*stack)->prev = tmp;
			*stack = tmp;
		}
	}
}

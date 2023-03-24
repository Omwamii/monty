#include "monty.h"

/**
 * push - push item to stack
 * @stack: pointer to top of stack
 * @line_number: current position at bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	int item;
	char *arg = strtok(NULL, " \n");

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	item = atoi(arg);
	if (item == 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = item;
	if (*stack == NULL) /* empty stack */
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		*stack = newnode;
	}
	else
	{
		newnode->next = *stack;
		newnode->prev = NULL;
		(*stack)->prev = newnode;
		*stack = newnode; /* newnode as topmost item (last in) */
	}
}

/**
 * pall - prints all items in stack
 * @stack: pointer to the top of stack
 * @line_number: line number of command
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints value at the top of stack followed by newline
 * @stack: ptr to top of stack
 * @line_number: current position at bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes top element of the stack
 * @stack: pointer to top of stack
 * @line_number: current position at bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: ptr to top of stack
 * @line_number: current position at bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *swap;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swap = (*stack)->next; /* second element */
	(*stack)->prev = swap;
	(*stack)->next = swap->next;
	swap->next = *stack;
	swap->prev = NULL;
	*stack = swap;
}

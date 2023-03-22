#include "monty.h"

/**
 * push - push item to stack
 * @stack: pointer to top of stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	int item;
	char *arg = strtok(NULL, " \n");

	item = atoi(arg);
	if (item == 0 && (strcmp(arg, "0") != 0))
	{
		fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
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

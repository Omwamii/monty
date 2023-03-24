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
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &divide},
		{"mul", &mul},
		{"mod", &mod},
		{"pchar", &pchar},
		{"pstr", &pstr},
		{"rotl", &rotl},
		{"rotr", &rotr},
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
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	f(stack, line_number); /* call handler fn */
}

/**
 * nop - implement opcode that does nothing
 * @stack: ptr to start of stack
 * @line_number: current file position
 */
void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number) {}

/**
 * queue - implements queue opcode
 * @stack: ptr to head of stack
 * @fp: file pointer
 * @line_number: current file position
 */
void queue(stack_t **stack, FILE *fp, unsigned int line_number)
{
	char *opcode = NULL, *buffer = NULL;
	size_t line_len = 0;

	while (getline(&buffer, &line_len, fp) != -1)
	{
		line_number++;
		opcode = strtok(buffer, " \n");
		if (!opcode || *opcode == '#')
			continue;
		if (strcmp(opcode, "stack") == 0)
			break;
		if (strcmp(opcode, "push") == 0)
			push_queue(stack, line_number);
		else
			execute_opcode(opcode, stack, line_number);
	}
	free(buffer);
}

/**
 * push_queue - push item to queue
 * @stack: pointer to head of stack
 * @line_number: current file position
 */
void push_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL, *tmp = *stack;
	int item;
	char *arg = strtok(NULL, " \n");

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	item = atoi(arg);
	if (item == 0 && (strcmp(arg, "0") != 0))
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
	if (*stack == NULL) /* empty queue */
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		*stack = newnode;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newnode; /* insert at end */
		newnode->next = NULL;
		newnode->prev = tmp;
	}
}

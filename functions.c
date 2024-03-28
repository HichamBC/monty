#include "monty.h"

/**
 * is_valid_integer - Checks if a string represents a valid integer.
 * @str: Pointer to the string to be validated as an integer.
 *
 *
 * Return:
 *   Returns 1 if the string represents a valid integer, and 0 otherwise.
 */

int is_valid_integer(const char *str)
{
	if (*str == '\0')
	{
		return (0);
	}

	if (*str == '-')
	{
		str++;
	}

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}

	return (1);
}


/**
 * push - Pushes an integer onto the stack
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file
 *
 * Return: None.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \t\n");
	stack_t *newNode = NULL;
	int value;

	if (value_str == NULL || !is_valid_integer(value_str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}

	*stack = newNode;
}

/**
 * pall - Prints all elements of the stack
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file (unused)
 *
 * Return: None.
 */

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * execute_instruction - Executes the instruction associated with the opcode
 *
 * @opcode: Opcode to execute
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file
 *
 * Return: None
 */

void execute_instruction(char *opcode, stack_t **stack,
			unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}


/**
 * free_stack - Frees all nodes in the stack.
 * @stack: Double pointer to the top of the stack.
 *
 * Return: None.
 */

void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	stack = NULL;
}

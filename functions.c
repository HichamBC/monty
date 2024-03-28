#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

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

	if (value_str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);
	if (value == 0 && strcmp(value_str, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

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
		{NULL, NULL}
	};
	int i;

	if (opcode[0] == '#')
		return;
	
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

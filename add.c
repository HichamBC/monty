#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file
 *
 * Return: None
 */

void add(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}

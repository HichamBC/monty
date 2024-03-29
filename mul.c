#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file
 *
 * Return: None
 */

void mul(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_number);
}

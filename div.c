#include "monty.h"

/**
 * _div - Divides the second top element of the stack by
 *	the top element of the stack.
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file
 *
 * Return: None
 */

void _div(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}


	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}

#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file
 *
 *
 * Return: None
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = ptr->next;

	temp = (*stack)->n;
	(*stack)->n = ptr->n;
	ptr->n = temp;
}

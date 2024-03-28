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
	stack_t *ptr = *stack;
	int count = 0;

	while (ptr != NULL && count < 2)
	{
		count++;
		ptr = ptr->next;
	}

	if (count != 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	*stack = (*stack)->next;

	(*stack)->n = ptr->n + (*stack)->n;
	free(ptr);
	ptr = NULL;
}

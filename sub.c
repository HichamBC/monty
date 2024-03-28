#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file
 *
 *
 * Return: None
 */

void sub(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	*stack = (*stack)->next;

	(*stack)->n = (*stack)->n - ptr->n;
	free(ptr);
	ptr = NULL;
}

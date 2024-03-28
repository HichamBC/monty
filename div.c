#include "monty.h"



void _div(stack_t **stack, unsigned int line_number)
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

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	*stack = (*stack)->next;

	(*stack)->n = (*stack)->n / ptr->n;
	free(ptr);
	ptr = NULL;
}

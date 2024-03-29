#include "monty.h"

/**
 * pstr - Prints the string contained in the stack
 *        until a non-printable character is encountered or
 *        the end of the stack is reached.
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file (unused)
 *
 * Return: None
 */

void pstr(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *ptr = *stack;

	while (ptr != NULL || ptr->n != 0 || check_ascii(ptr->n) != 0)
	{
		if (ptr->n == 0)
		{
			break;
		}

		putchar((char) ptr->n);
		ptr = ptr->next;
	}

	putchar('\n');
}

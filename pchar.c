#include "monty.h"

/**
 * check_ascii - Checks if a character is a valid ASCII character.
 *
 * @c: The character to check.
 *
 * Return: 1 if the character is an ASCII character, 0 otherwise.
 */

int check_ascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/**
 * pchar - prints the char at the top of the stack
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction in the file
 *
 *
 * Return: None
 */

void pchar(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (check_ascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

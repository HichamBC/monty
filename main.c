#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"


/**
 * main - Entry point for the Monty interpreter
 *
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 *
 * Return: 0 on successful execution, EXIT_FAILURE if an error occurs.
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char buffer[100];
	char *s;
	unsigned int line = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		line++;

		s = strtok(buffer, " \t\n");
		if (s == NULL || s[0] == '#')
		{
			continue;
		}

		execute_instruction(s, &stack, line);
	}

	free_stack(stack);
	fclose(fp);
	return (0);
}

#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * getfunc - gets functions
 * @instruct: the opcode
 * @value: value to be pushed
 * @line_number: line being parsed
 *
 * Return: void
 */
void (*getfunc(char *instruct))(stack_t **stack, unsigned int line_number)
{
	int cp, i;

	instruction_t op[] = {
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};

	i = 0;
	while(op[i].f != NULL)
	{
		cp = strcmp(op[i].opcode, instruct);
		if (cp == 0)
		{
			return (op[i].f);
		}
		i++;
	}
	return (NULL);
}

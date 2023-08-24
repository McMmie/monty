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
void getfunc(char *instruct, unsigned int value, unsigned int line_number)
{
	int cmp1 = strcmp(instruct, "push"), cmp2 = strcmp(instruct, "nop"), n, cp, i;

	void (*fptr[LIMIT])(stack_t *, unsigned int) = {
			&pop,
			&pall,
			&pint,
			&swap,
			&add
		};
	char *opcode[LIMIT] = {
		"pop",
		"pall",
		"pint",
		"swap",
		"add"
	};
	stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

	if (cmp1 == 0)
	{
		push(&stack, value);
		return;
	}
	else if (cmp2 == 0)
	{
		return;
	}
	else
	{
		n = sizeof(opcode) / sizeof(char *);
		for (i = 0; i < n; i++)
		{
			cp = strcmp(opcode[i], instruct);
			if (cmp == 0)
			{
				fptr[i](stack, line_number);
				return;
			}
		}
	}
}

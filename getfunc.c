#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * getfunc - gets functions
 * @instruction: the opcode
 * @value: value to be pushed
 *
 * Return: void
 */
#define LIMIT 10
void getfunc(char *instruction, unsigned int value, unsigned int line_number)
{
	int cmp, num, i;
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

	instruction_t *func = (instruction_t *)malloc(sizeof(instruction_t));
	stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

	func->opcode = instruction;
	if ((cmp = strcmp(instruction, "push")) == 0)
	{
		push(&stack, value);
		return;
	}
	else if ((cmp = strcmp(instruction, "nop")) == 0)
	{
		return;
	}
	else
	{
		num = sizeof(opcode) / sizeof(char *);
		for (i = 0; i < num; i++)
		{
			cmp = strcmp(opcode[i], func->opcode);
			if (cmp == 0)
			{
				fptr[i](stack, line_number);
				return;
			}
		}
	}
}

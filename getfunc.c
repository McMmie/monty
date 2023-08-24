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
void getfunc(char *instruction, unsigned int value)
{
	int cmp, num, i;
	char *opcode[LIMIT] = {
		"pop",
		"pall",
		"pint",
		"swap",
		"add",
		"nop"
	};
	instruction_t *func = (instruction_t *)malloc(sizeof(instruction_t));
	stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

	func->opcode = instruction;
	if ((cmp = strcmp(instruction, "push")) == 0)
	{
		push(&stack, value);
		printf("executed!\n");
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
				printf("printing all");
				pall(stack);
				return;
			}
		}
	}
}

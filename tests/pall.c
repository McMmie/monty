#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - prints all the elements in a stack
 * @stack: points to a stack
 *
 * Return: void
 */
void pall(stack_t *stack)
{
	int i = 1;
	stack_t *tmp;
	tmp = stack;
	if (stack == NULL)
	{
		printf("empity");
		return;
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

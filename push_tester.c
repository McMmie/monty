#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	stack_t *stack = NULL, *tmp = NULL;
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);

	tmp = stack;
	while (tmp->next != NULL)
	{
		printf("n: %d\n", tmp->n);
		tmp= tmp->next;

	}
		printf("check\n");

	return 0;
}


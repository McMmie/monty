#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - adds an element to the top of the stack
 * @stack: a doubly linked list
 * @line_number: value of element
 *
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *top, *tmp;

	if(stack == NULL)
	{
		fprintf(stderr, "no stack found");
		exit(EXIT_FAILURE);
	}

	top = (stack_t *)malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	top->prev = NULL;
	top->next = NULL;
	if (*stack == NULL)
	{
		*stack = top;
		top->n = line_number;
		tmp = top;
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			i++;
		}
		tmp->next = top;
		top->prev = tmp;
		top->n = line_number;
		tmp->next->prev = top;
	}
}

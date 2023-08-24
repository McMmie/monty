#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - adds an element to the top of the stack
 * @stack: a doubly linked list
 * @value: value to be pushed
 *
 * Return: nothing
 */

void push(stack_t **stack, unsigned int value)
{
	int i = 0;
	stack_t *top, *tmp;

	if (stack == NULL)
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
		top->n = value;
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
		top->n = value;
		tmp->next->prev = top;
	}
}

/**
 * pall - prints all the elements in a stack
 * @stack: points to a stack
 * @line_number: line being parsed currently
 *
 * Return: void
 */
void pall(stack_t *stack, unsigned int __attribute__((unused))line_number)
{
	int i = 1;
	stack_t *tmp;

	tmp = stack;
	if (stack == NULL)
	{
		printf("empity\n");
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
/**
 * pop - removes the top element
 * @stack: points to a stack
 * @line_number: line being parsed
 *
 * Return: void
 */
void pop(stack_t *stack, unsigned int line_number)
{
	int i = 1;
	stack_t *tmp, *top;

	tmp = stack;
	if (stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		return;
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}

	top = tmp->next;
	free(top);
	tmp->next = NULL;
}

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
	stack_t *top;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	top->n = value;
	if (*stack == NULL)
	{
		*stack = top;
		top->prev = NULL;
		top->next = NULL;
	}
	else
	{
		top->next = *stack;
		(*stack)->prev = top;
		*stack = top;
	}
}

/**
 * pall - prints all the elements in a stack
 * @stack: points to a stack
 * @line_number: line being parsed currently
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		printf("empity\n");
		return;
	}
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop - removes the top element
 * @stack: points to a stack
 * @line_number: line being parsed
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		return;
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}

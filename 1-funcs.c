#include "monty.h"
#include <stdio.h>

/**
 * pint - prints the top element
 * @stack: a doubly linked list
 * @line_number: line which is currently being read
 *
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * swap - swaps the top two elements
 * @stack: points to the first node of a list
 * @line_number: line which is currently being read
 *
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short", line_number);
		return;
	}

	tmp = *stack;
	if (tmp->next != NULL)
	{
		(*stack)->next = tmp->next;
		tmp->prev = *stack;
	}
	else
	{
		tmp->prev = NULL;
		tmp->next = *stack;
		*stack = tmp;
	}
}

/**
 * add - adds al the values of a stack
 * @stack: points to the first node of a list
 * @line_number: line being read currently
 *
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *tmp, *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short", line_number);
		return;
	}

	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if ((i + 1) < 2)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short", line_number);
	}
	else
	{
		top = tmp->next;
		tmp->n += top->n;
		free(top);
		tmp->next = NULL;
		top = tmp;
	}
}
/**
 * nop - does nothing
 *
 * Return: nothing
 */

void nop(stack_t __attribute__((unused))**stack, unsigned int __attribute__((unused))line_number)
{

}

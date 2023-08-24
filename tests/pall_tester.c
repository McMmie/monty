#include "monty.h"
#include <stdio.h>
#include <stdlib.h> // Include this for malloc

typedef struct stack_t {
    int n;
    struct stack_t *prev;
    struct stack_t *next;
} stack_t;

void pall(stack_t *stack);

int main()
{
    int i, j = 1;
    stack_t *head = NULL, *stk = NULL, *tmp = NULL;

    for (i = 0; i < 4; i++)
    {
        stk = (stack_t *)malloc(sizeof(stack_t));
        if (stk == NULL)
        {
            // Handle allocation failure
            return 1;
        }
        stk->n = j++;
        stk->prev = tmp;
        stk->next = NULL;

        if (tmp != NULL)
        {
            tmp->next = stk;
        }
        else
        {
            head = stk;
        }
        tmp = stk;
        printf("n: %d\n", stk->n);
    }

    pall(head);
    return 0;
}

void pall(stack_t *stack)
{
    if (stack == NULL)
    {
        printf("empty\n");
        return;
    }

    while (stack != NULL)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}


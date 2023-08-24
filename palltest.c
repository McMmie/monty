#include <stdio.h>
#include <stdlib.h>
/**
 * doc
 */

int main()
{
	int i, j = 1;
	stack_t *head = NULL, *stk = NULL, *tmp = NULL;
	
	for (i = 0;i < 4; i++)
	{
		stk = (stack_t *)malloc(sizeof(stack_t));
		if(stk == NULL)
		{
			printf("error!!\n");
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
	}
	pall(head);
	return 0;
}



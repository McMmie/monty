#define _GNU_SOURCE
#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/**
 * main - checks the code
 * @argc: argument count
 * @argv: an array of arguments
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	unsigned int i, num, cmp, line = 0;
	FILE *fd;
	size_t n = 0;
	ssize_t res;
	char *token, *array[2], *buffer = NULL;
	stack_t *tmp, *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line++;
		res = getline(&buffer, &n, fd);
		if (res == -1)
		{
			perror(argv[1]);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		token = strtok(buffer, " ,.;:!\n\t\r");
		i = 0;
		while (token != NULL)
		{
			array[i++] = token;
			token = strtok(NULL, "\n\t\r;: ,.!");
		}
		num = convert(array, line);
		printf("checkpoint 1");
		if ((cmp = strcmp(token, "push")) == 0)
		{
			push(&stack, num);
		}
		else
		(getfunc(*array))(&stack, line);
	}
	fclose(fd);
	free(buffer);
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	return (0);
}

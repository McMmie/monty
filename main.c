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
	unsigned int num, i, j, line = 0;
	FILE *fd;
	size_t n = 0;
	ssize_t res;
	char *token, *array[2], *buffer = NULL;

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
	res = getline(&buffer, &n, fd);
	if (res == -1)
	{
		perror(argv[1]);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " ,.!");
	for (i = 0; token != NULL && i < 2; i++)
	{
		array[i] = token;
		token = strtok(NULL, " ,.!");
	}
	for (j = 0; array[1][j] != '\0'; j++)
	{
		if (!isdigit(array[1][j]))
		{
			exit(EXIT_FAILURE);
		}
		else
		{
			num = atoi(array[1]);
			break;
		}
	}
	printf("checkpoint 1\n");
	getfunc(array[0], num, ++line);
	}
	printf("checkpoint 4:\n");
	fclose(fd);
	free(buffer);
	return (0);
}

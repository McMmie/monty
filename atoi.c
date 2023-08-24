#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * convert - converts string to integer
 * @array: stream from file
 * @line_number: line being parsed
 *
 * Return: an integer
 */

unsigned int convert(char **array, unsigned int line_number)
{
	int j, num;

	for (j = 0; array[1][j] != '\0'; j++)
	{
		if (!isdigit(array[1][j]))
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			num = atoi(array[1]);
			break;
		}
	}
	return (num);
}

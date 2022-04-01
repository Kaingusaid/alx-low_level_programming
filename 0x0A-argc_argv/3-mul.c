#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *  main - program that multiplies two numbers.
 *   @argc: count
 *    @argv: vector
 *    Return: output
 */
int main(int argc, char **argv)
{
	int n1;
	int n2;
	int result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[2]);
		result = n1 * n2;

		printf("%d\n", result);
	}
	return (0);
}

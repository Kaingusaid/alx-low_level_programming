#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - program that prints the opcodes of its own main function.
 * @argc: counter
 * @argv: vector
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	int i;
	int bytes;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	bytes = atoi(argv[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}
	for (i = 0; i < bytes; i++)
	{
		printf("%02x", ((unsigned char *)main)[i]);
		if (i != (bytes - 1))
			printf(" ");
		else
			printf("\n");
	}
	return (0);
}

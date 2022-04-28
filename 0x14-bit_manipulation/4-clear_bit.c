#include "main.h"

/**
 * clear_bit - sets the value of a bit at a given index to 0
 * @n: a pointer to the integer whose bit is to be modified
 * @index: the index of the bit to modify
 * Return: 1 for success and -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	int mask;

	if (n == NULL || index > ((sizeof(unsigned long int) * 8) - 1))
		return (-1);
	mask = 1 << index;
	*n = (*n & ~mask);
	return (1);
}

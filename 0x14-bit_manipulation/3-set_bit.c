#include "main.h"

/**
 * set_bit - set the value of a certain index bit to 1
 * @n: a pointer to the integer to be modified
 * @index: the index of the bit to be set
 * Return: 1 if success and -1 if failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || (index > ((sizeof(unsigned long int) * 8) - 1)))
		return (-1);
	*n = (*n | (1 << index));
	return (1);
}

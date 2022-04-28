#include "main.h"

/**
 * binary_to_uint - convert a binary to an unsigned int
 * @b: a pointer to a string of 0 and 1
 * Return: the converted number or 0 if fails
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ret = 0;
	int i, j;

	if (b == NULL)
		return (0);
	for (i = 0; b[i + 1]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}
	for (j = 1; i >= 0; i--, j *= 2)
		ret += ((b[i] - '0') * (j));
	return (ret);
}

#include "main.h"

/**
 * flip_bits - figure out how many bits need to be flipped to convert number
 * @n: the number whose bits are to be flipped
 * @m: the number the bit flip should result in
 * Return: the number of flips to achieve the conversion
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int ret, i;

	for (i = 0, ret = 0; i < (sizeof(unsigned long int) * 8); i++)
	{
		if ((n & 1) != (m & 1))
			ret++;
		n >>= 1, m >>= 1;
	}
	return (ret);
}

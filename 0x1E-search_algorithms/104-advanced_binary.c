#include "search_algos.h"
/**
 * advanced_binary_recursive - searches for a value in an array of
 * integers using the binary search algorithm.
 *
 * @array:  pointer to the first element of the array to search in
 * @lo: lowest index of the array
 * @hi: highest index of the array
 * @value: value to search in the array
 *
 * Return: index of found value or -1
 */
int advanced_binary_recursive(int *array, size_t lo, size_t hi, int value)
{
	int mid = (hi + lo) / 2;
	size_t i = 0;

	if (hi >= lo)
	{
		printf("Searching in array: ");
		for (i = lo; i <= hi; i++)
		{
			if (i != hi)
				printf("%d, ", array[i]);
			else
				printf("%d\n", array[i]);
		}
		if (value > array[mid - 1] && value == array[mid])
			return (mid);
		else if (value > array[mid])
			return (advanced_binary_recursive(array, mid + 1, hi, value));
		else
			return (advanced_binary_recursive(array, lo, mid, value));
	}
	return (-1);
}
/**
 * advanced_binary - searches for a value in an array of
 * integers using the binary search algorithm.
 *
 * @array:  pointer to the first element of the array to search in
 * @size: size of the array
 * @value: value to search in the array
 *
 * Return: index of found value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int lo = 0, hi = size - 1;

	if (array == NULL)
		return (-1);

	return (advanced_binary_recursive(array, lo, hi, value));
}

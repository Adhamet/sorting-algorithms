#include "sort.h"

/* helper functions */
void swap(int *a, int *b);
void qs(int *array, int low, int high, int size);
int partition(int *array, int low, int high, int size);

/**
 * quick_sort - prepares for quick sort implementation
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qs(array, 0, size - 1, size);
}

/**
 * qs - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to sort
 * @low: the low index
 * @high: the high index
 * @size: size of array
 */
void qs(int *array, int low, int high, int size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		qs(array, low, pi - 1, size);
		qs(array, pi + 1, high, size);
	}
}

/**
 * partition - partitions the array
 * @array: array to partition
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: index resulting from partition
 */
int partition(int *array, int low, int high, int size)
{
	int pivot = array[high], i = (low - 1), j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap - function that swaps values of array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

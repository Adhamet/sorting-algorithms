#include "sort.h"

/**
 * shell_sort - sorts an array of integers in
 * ascending order using the Shell Sort algorithm
 * @array: array to sort
 * @size: size of array
 * Note:
 * to calculate next gap: h=(h*3)+1
 * to calculate last gap: h=(h-1)/3
 * Average/Best Case: O(nlog(n))
 * Worst Case: O(n^2)
 */
void shell_sort(int *array, size_t size)
{
	size_t in, out, h = 1;
	int tmp;

	if (!array || size < 2)
		return;

	while (h <= size / 3)
		h = (h * 3) + 1;

	while (h > 0)
	{
		for (out = h; out < size; out++)
		{
			tmp = array[out];
			in = out;

			while (in >= h && array[in - h] > tmp)
			{
				array[in] = array[in - h];
				in -= h;
			}
			array[in] = tmp;
		}

		h = (h - 1) / 3;
		print_array(array, size);
	}
}

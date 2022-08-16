#include "sort.h"

/**
  * smallest - Computes for the smallest element of the array.
  * @array: The array to compute for the element.
  * @size: The size of the array.
  * @k: The index of the smallest value.
  *
  * Return: The position of the smallest element.
  */

int smallest(int *array, size_t k, size_t size)
{
	size_t i, pos = k;

	int small = array[k];

	for (i = k + 1; i < size; i++)
	{
		if (array[i] < small)
		{
			small = array[i];
			pos = i;
		}
	}

	return (pos);
}

/**
  * selection_sort - Sorts an array of integers in ascending order
  *                 using the Selection sort algorithm.
  * @array: The array of elements to sort.
  * @size: The number of elements of the array.
  *
  */

void selection_sort(int *array, size_t size)
{
	size_t k, pos;

	int temp;

	for (k = 0; k < size; k++)
	{
		pos = smallest(array, k, size);
		if (k != pos)
		{
			temp = array[k];
			array[k] = array[pos];
			array[pos] = temp;
			print_array(array, size);
		}
	}
}

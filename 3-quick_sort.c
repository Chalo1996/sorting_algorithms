#include "sort.h"


/**
  * partition - partitions the array into two.
  * @arr: array to partition.
  * @low: index zero.
  * @high: last index.
  * @size: size of the array.
  *
  * Return: index of pivot.
  */

size_t partition(int *arr, ssize_t low, ssize_t high, size_t size)
{
	int pivot, temp;
	ssize_t j, i;

	j = low - 1;
	pivot = arr[high];

	for (i = low; i < high; i++)
	{
		if (arr[i] < pivot)
		{
			j++;
			if (i != j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				print_array(arr, size);
			}
		}
	}

	if (arr[j + 1] > arr[high])
	{
		temp = arr[j + 1];
		arr[j + 1] = arr[high];
		arr[high] = temp;
		print_array(arr, size);
	}

	return (j + 1);
}

/**
  * quick_sort_algo - sorts the array.
  * @arr: the array to sort.
  * @low: first index.
  * @high: last index.
  * @size: size of the array.
  *
  */

void quick_sort_algo(int *arr, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high, size);
		quick_sort_algo(arr, low, pivot - 1, size);
		quick_sort_algo(arr, pivot + 1, high, size);
	}
}

/**
  * quick_sort -  sorts an array of integers in ascending
  *               order using the Quick sort algorithm. This
  *               algorithm uses the Lomuto partion schema.
  * @array: The array to sort.
  * @size: The number of elements.
  *
  */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_algo(array, 0, size - 1, size);
}

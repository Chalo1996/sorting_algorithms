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
	int temp, flag;
	ssize_t loc;

	loc = low;

	while (flag != 1)
	{
		while ((arr[loc] < arr[high]) && (loc != high))
		{
			high--;
		}
		if (loc == high)
			flag = 1;

		else if (arr[loc] > arr[high])
		{
			temp = arr[loc];
			arr[loc] = arr[high];
			arr[high] = temp;
			loc = high;
			print_array(arr, size);
		}
		if (flag != 1)
		{
			while ((arr[loc] >= arr[low]) && (loc != low))
				low++;
			if (loc == low)
				flag = 1;
			else if (arr[loc] < arr[low])
			{
				temp = arr[loc];
				arr[loc] = arr[low];
				arr[low] = temp;
				loc = low;
				print_array(arr, size);
			}
		}
	}

	return (loc);
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
  * quick_sort_hoare -  sorts an array of integers in ascending
  *               order using the Quick sort algorithm. This
  *               algorithm uses the Lomuto partion schema.
  * @array: The array to sort.
  * @size: The number of elements.
  *
  */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_algo(array, 0, size - 1, size);
}

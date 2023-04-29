#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - recursive helper function for quick_sort
 * @array: array of integers to be sorted
 * @low: index of the first element of the partition being sorted
 * @high: index of the last element of the partition being sorted
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high, size);
        quick_sort_helper(array, low, pivot - 1, size);
        quick_sort_helper(array, pivot + 1, high, size);
    }
}

/**
 * partition - partitions the array using the Lomuto scheme
 * @array: array of integers to be sorted
 * @low: index of the first element of the partition being sorted
 * @high: index of the last element of the partition being sorted
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot, i, j, tmp;

    pivot = array[high];
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                print_array(array, size);
            }
        }
    }
    if (i + 1 != high)
    {
        tmp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = tmp;
        print_array(array, size);
    }
    return (i + 1);
}

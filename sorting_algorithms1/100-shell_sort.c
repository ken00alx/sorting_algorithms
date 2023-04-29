#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void shell_sort(int *array, size_t size) {
    int interval = 1;
    while (interval <= size / 3) {
        interval = interval * 3 + 1;
    }
    while (interval > 0) {
        for (size_t i = interval; i < size; ++i) {
            int temp = array[i];
            size_t j = i;
            while (j >= interval && array[j - interval] > temp) {
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = temp;
        }
        interval = (interval - 1) / 3;
        for (size_t i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

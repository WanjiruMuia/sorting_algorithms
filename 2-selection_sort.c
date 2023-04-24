#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void selection_sort(int *array, size_t size) {
    size_t i, j, min_idx;
    int temp;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
            /* Print the array after each swap */
            printf("Swap %d <-> %d: ", array[i], array[min_idx]);
            for (int k = 0; k < size; k++) {
                printf("%d ", array[k]);
            }
            printf("\n");
        }
    }
}

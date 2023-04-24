#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bubble_sort(int *array, size_t size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                /* Print the array after each swap */
                printf("Swap %d <-> %d: ", array[j], array[j + 1]);
                for (int k = 0; k < size; k++) {
                    printf("%d ", array[k]);
                }
                printf("\n");
            }
        }
    }
}

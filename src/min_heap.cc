#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dvs/min_heap.h"

void min_heapify_array(int len, int *heap_as_array, int root_index)
{
        int smallest_index;
        int left_index = 2 * root_index + 1;
        int right_index = 2 * root_index + 2;

        if (left_index < len && heap_as_array[left_index] < heap_as_array[root_index]) {
                smallest_index = left_index;
        } else {
                smallest_index = root_index;
        }

        if (right_index < len && heap_as_array[right_index] < heap_as_array[smallest_index]) {
                smallest_index = right_index;
        }

        if (smallest_index != root_index) {
                int tmp = heap_as_array[root_index];
                heap_as_array[root_index] = heap_as_array[smallest_index];
                heap_as_array[smallest_index] = tmp;

                min_heapify_array(len, heap_as_array, smallest_index);
        }
}

int *build_min_heap(int num_elements, int *elements)
{
        int *ret = (int *) malloc(sizeof(int) * num_elements);

        for (int i = num_elements / 2; i >= 0; --i) {
                min_heapify_array(num_elements, elements, i);
        }

        memcpy((void *) ret, (void *) elements, sizeof(int) * num_elements);

        return ret;
}

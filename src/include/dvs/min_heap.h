#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__

template <typename T>
void min_heapify_array(int len, T *heap_as_array, int root_index)
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
                T tmp = heap_as_array[root_index];
                heap_as_array[root_index] = heap_as_array[smallest_index];
                heap_as_array[smallest_index] = tmp;

                min_heapify_array(len, heap_as_array, smallest_index);
        }
}

template <typename T>
T *build_min_heap(int num_elements, T *elements)
{
        T *ret = (T *) malloc(sizeof(T) * num_elements);

        for (int i = num_elements / 2; i >= 0; --i) {
                min_heapify_array(num_elements, elements, i);
        }

        memcpy((void *) ret, (void *) elements, sizeof(T) * num_elements);

        return ret;
}

#endif

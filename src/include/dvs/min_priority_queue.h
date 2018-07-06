#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__

#include <cassert>

void set_key(int *pq_as_array, int i, int k)
{
    assert(k <= pq_as_array[i]);
    pq_as_array[i] = k;
    int parent_index = (i - 1) / 2;

    while (i > 0 && pq_as_array[parent_index] > pq_as_array[i]) {
        int tmp = pq_as_array[parent_index];
        pq_as_array[parent_index] = pq_as_array[i];
        pq_as_array[i] = tmp;
        i = (i - 1) / 2;
        parent_index =  (i - 1) / 2;
    }
}

#endif

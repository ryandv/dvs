#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__

#include <stdio.h>

void min_heapify_array(int len, int *heap_as_array, int root_index);
int *build_min_heap(int num_elements, int *elements);

#endif

#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__

#include <vector>

template <typename T>
class Heap
{
    public:
        Heap() : heapVec (std::vector<T>()) { }
        Heap(const std::vector<T> &elements) : heapVec (std::vector<T>(elements)) { }
        T at(int index)
        {
            return heapVec.at(index);
        }
    private:
        std::vector<T> heapVec;
};

template <typename T>
void min_heapify_vec(int len, std::vector<T> &heap_as_vec, int root_index)
{
        int smallest_index;
        int left_index = 2 * root_index + 1;
        int right_index = 2 * root_index + 2;

        if (left_index < len && heap_as_vec.at(left_index) < heap_as_vec.at(root_index)) {
                smallest_index = left_index;
        } else {
                smallest_index = root_index;
        }

        if (right_index < len && heap_as_vec.at(right_index) < heap_as_vec.at(smallest_index)) {
                smallest_index = right_index;
        }

        if (smallest_index != root_index) {
                T tmp = heap_as_vec.at(root_index);
                heap_as_vec.at(root_index) = heap_as_vec.at(smallest_index);
                heap_as_vec.at(smallest_index) = tmp;

                min_heapify_vec(len, heap_as_vec, smallest_index);
        }
}

template <typename T>
Heap<T> build_min_heap(int num_elements, const std::vector<T> &elements)
{
        std::vector<T> ret = std::vector<T>(elements);

        for (int i = num_elements / 2; i >= 0; --i) {
                min_heapify_vec(num_elements, ret, i);
        }

        return Heap<T>(ret);
}

#endif

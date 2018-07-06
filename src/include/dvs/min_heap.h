#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__

#include <cassert>
#include <cstdlib>
#include <vector>

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
class Heap
{
    public:
        Heap() : heap_vec (std::vector<T>()) { }
        Heap(const std::vector<T> &elements) : heap_vec (build_min_heap_vec(elements)) { }

        T at(int index)
        {
            return heap_vec.at(index);
        }

        void set_key(int i, int k)
        {
            assert(k <= heap_vec.at(i));

            heap_vec.at(i) = k;
            int parent_index = (i - 1) / 2;

            while (i > 0 && heap_vec.at(parent_index) > heap_vec.at(i)) {
                int tmp = heap_vec.at(parent_index);
                heap_vec.at(parent_index) = heap_vec.at(i);
                heap_vec.at(i) = tmp;
                i = (i - 1) / 2;
                parent_index =  (i - 1) / 2;
            }
        }

        std::size_t size()
        {
            return heap_vec.size();
        }
    private:
        std::vector<T> heap_vec;

        std::vector<T> build_min_heap_vec(const std::vector<T> &elements)
        {
            int num_elements = elements.size();
            std::vector<T> ret = std::vector<T>(elements);

            for (int i = num_elements / 2; i >= 0; --i) {
                min_heapify_vec(num_elements, ret, i);
            }

            return ret;
        }
};

#endif

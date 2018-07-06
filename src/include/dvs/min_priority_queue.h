#ifndef __MIN_PRIORITY_QUEUE_H__
#define __MIN_PRIORITY_QUEUE_H__

#include <cassert>
#include <vector>

template <typename T>
void set_key(std::vector<T> &pq_as_vec, int i, int k)
{
    assert(k <= pq_as_vec.at(i));
    pq_as_vec.at(i) = k;
    int parent_index = (i - 1) / 2;

    while (i > 0 && pq_as_vec.at(parent_index) > pq_as_vec.at(i)) {
        int tmp = pq_as_vec.at(parent_index);
        pq_as_vec.at(parent_index) = pq_as_vec.at(i);
        pq_as_vec.at(i) = tmp;
        i = (i - 1) / 2;
        parent_index =  (i - 1) / 2;
    }
}

#endif

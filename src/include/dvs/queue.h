#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__

#include <cstdlib>
#include <vector>

template <typename T>
class Queue {
    public:
    Queue() : queue_vec(std::vector<T>()) { }
    std::size_t size()
    {
        return queue_vec.size();
    }

    private:
        std::vector<T> queue_vec;
};

#endif

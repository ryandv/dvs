#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <cstdlib>
#include <memory>
#include <vector>

template <typename T>
class BoundedQueue {
    public:
    BoundedQueue()
        : queue_arr(std::unique_ptr<T[]>())
        , head(0)
        , tail(0)
        , max_size(0)
    {}

    BoundedQueue(unsigned int max_size)
        : queue_arr(std::unique_ptr<T[]>(new T[max_size]))
        , head(0)
        , tail(0)
        , max_size(max_size)
    {
    }

    std::size_t size()
    {
        if (tail < head) {
            return (tail + max_size - 1) - head;
        } else {
            return tail - head;
        }
    }

    void enqueue(T val)
    {
        (queue_arr.get())[tail] = val;

        if (tail == (max_size - 1)) {
            tail = 1;
        } else {
            tail += 1;
        }
    }

    const T dequeue()
    {
        T val = (queue_arr.get())[head];

        if (head == size()) {
            head = 1;
        } else {
            head += 1;
        }

        return val;
    }

    private:
        std::unique_ptr<T[]> queue_arr;
        unsigned int max_size;
        std::size_t head;
        std::size_t tail;
};

#endif

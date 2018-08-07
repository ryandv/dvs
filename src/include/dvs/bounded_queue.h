#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <cstdlib>
#include <memory>
#include <vector>

template <typename T>
class BoundedQueue {
    public:

    class BoundedQueueOverflow : public std::exception { };

    BoundedQueue()
        : queue_arr(std::unique_ptr<T[]>())
        , head(0)
        , tail(0)
        , max_size(0)
    {
    }

    BoundedQueue(unsigned int max_size)
        : queue_arr(std::unique_ptr<T[]>(new T[max_size + 1]))
        , head(0)
        , tail(0)
        , max_size(max_size)
    {
    }

    int size()
    {
        if (tail <= head) {
            int size = (tail + max_size) - head - 1;
            return size < 0 ? 0 : size;
        } else {
            return tail - head;
        }
    }

    void enqueue(T val)
    {
        if (head == tail + 1) { throw BoundedQueueOverflow(); }

        (queue_arr.get())[tail] = val;

        if (tail == max_size) {
            tail = 0;
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
        int head;
        int tail;
};

#endif

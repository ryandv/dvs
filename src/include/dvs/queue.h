#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <cstdlib>
#include <vector>

template <typename T>
class Queue {
    public:
    Queue()
        : queue_vec(std::vector<T>())
        , head(0)
        , tail(0)
    { }

    std::size_t size()
    {
        if (tail < head) {
            return (tail + queue_vec.capacity()) - head;
        } else {
            return tail - head;
        }
    }

    void enqueue(T val)
    {
        if (queue_vec.empty()) {
            queue_vec.push_back(val);
            head = 0;
        } else {
            queue_vec.at(tail) = val;
        }

        if (tail == queue_vec.size()) {
            tail = 1;
        } else {
            tail += 1;
        }
    }

    const T dequeue()
    {
        T val = queue_vec.at(head);

        if (head == size()) {
            head = 1;
        } else {
            head += 1;
        }

        return val;
    }

    private:
        std::vector<T> queue_vec;
        std::size_t head;
        std::size_t tail;
};

#endif

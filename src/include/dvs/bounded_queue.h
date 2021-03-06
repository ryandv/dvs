#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <cstdlib>
#include <cmath>
#include <memory>
#include <vector>

template <typename T>
class BoundedQueue {
    public:

    class BoundedQueueOverflow : public std::exception {
        const char *what() const noexcept override
        {
            return "Bounded queue overflow";
        }
    };

    class BoundedQueueUnderflow : public std::exception {
        const char *what() const noexcept override
        {
            return "Bounded queue underflow";
        }
    };

    BoundedQueue()
        : queue_arr(std::unique_ptr<T[]>(new T[1]))
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
            return fmax(size, 0);
        } else {
            return tail - head;
        }
    }

    void enqueue(T val)
    {
        if (max_size == 0 || head == ((tail + 1) % (max_size + 1))) { throw BoundedQueueOverflow(); }

        (queue_arr.get())[tail] = val;

        if (tail == max_size) {
            tail = 0;
        } else {
            tail += 1;
        }
    }

    const T dequeue()
    {
        if (head == tail) { throw BoundedQueueUnderflow(); }

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

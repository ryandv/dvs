#include <stdio.h>
#include <stdexcept>
#include <vector>

#include "gtest/gtest.h"

#include "dvs/bounded_queue.h"

namespace {
    class BoundedQueueTest : public ::testing::Test {
        protected:
            virtual void SetUp()
            {
            }
    };
}

TEST_F(BoundedQueueTest, build_empty_bounded_queue)
{
    BoundedQueue<int> q;
    ASSERT_EQ(q.size(), 0);
}

TEST_F(BoundedQueueTest, enqueue_increments_size)
{
    BoundedQueue<int> q(1);
    q.enqueue(1);
    ASSERT_EQ(q.size(), 1);
}

TEST_F(BoundedQueueTest, dequeue_decrements_size)
{
    BoundedQueue<int> q(1);
    q.enqueue(1);
    int head = q.dequeue();

    ASSERT_EQ(head, 1);
    ASSERT_EQ(q.size(), 0);
}

TEST_F(BoundedQueueTest, obeys_fifo)
{
    BoundedQueue<int> q(2);
    q.enqueue(1);
    q.enqueue(2);

    int first = q.dequeue();
    int second = q.dequeue();

    ASSERT_EQ(first, 1);
    ASSERT_EQ(second, 2);
}

TEST_F(BoundedQueueTest, raises_error_on_overflow)
{
    BoundedQueue<int> q;
    EXPECT_THROW(q.enqueue(1), BoundedQueue<int>::BoundedQueueOverflow);
}

TEST_F(BoundedQueueTest, raises_error_on_underflow)
{
}

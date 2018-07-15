#include <stdio.h>
#include <stdexcept>
#include <vector>

#include "gtest/gtest.h"

#include "dvs/queue.h"

namespace {
    class QueueTest : public ::testing::Test {
        protected:
            virtual void SetUp()
            {
            }
    };
}

TEST_F(QueueTest, build_empty_queue)
{
    Queue<int> q;
    ASSERT_EQ(q.size(), 0);
}

TEST_F(QueueTest, enqueue_increments_size)
{
    Queue<int> q;
    q.enqueue(1);
    ASSERT_EQ(q.size(), 1);
}

TEST_F(QueueTest, dequeue_decrements_size)
{
    Queue<int> q;
    q.enqueue(1);
    int head = q.dequeue();

    ASSERT_EQ(head, 1);
    ASSERT_EQ(q.size(), 0);
}

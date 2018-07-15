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

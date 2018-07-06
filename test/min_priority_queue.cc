#include <stdio.h>
#include <vector>

#include "gtest/gtest.h"

#include "dvs/min_priority_queue.h"

namespace {
    class MinPriorityQueueTest : public ::testing::Test {
        protected:
            virtual void SetUp()
            {
            }
    };
}

TEST_F(MinPriorityQueueTest, set_key_singleton)
{
    std::vector<int> min_pq = { 100 };
    set_key(min_pq, 0, 1);
    ASSERT_EQ(min_pq.at(0), 1);
}


TEST_F(MinPriorityQueueTest, set_key_raises_if_new_key_is_greater_than_current)
{
    std::vector<int> min_pq = { 1 };
    ASSERT_DEATH(set_key(min_pq, 0, 100), "Assertion `k <= pq_as_vec.at\\(i\\)' failed");
}

TEST_F(MinPriorityQueueTest, set_key_recursive_left_subtree)
{
    std::vector<int> min_pq = { 2, 3, 4, 5, 6 };
    set_key(min_pq, 4, 1);
    ASSERT_EQ(min_pq.at(0), 1);
    ASSERT_EQ(min_pq.at(1), 2);
    ASSERT_EQ(min_pq.at(2), 4);
    ASSERT_EQ(min_pq.at(3), 5);
    ASSERT_EQ(min_pq.at(4), 3);
}

TEST_F(MinPriorityQueueTest, set_key_recursive_right_subtree)
{
    std::vector<int> min_pq = { 2, 3, 4, 5, 6, 7, 8 };
    set_key(min_pq, 6, 1);
    ASSERT_EQ(min_pq.at(0), 1);
    ASSERT_EQ(min_pq.at(1), 3);
    ASSERT_EQ(min_pq.at(2), 2);
    ASSERT_EQ(min_pq.at(3), 5);
    ASSERT_EQ(min_pq.at(4), 6);
    ASSERT_EQ(min_pq.at(5), 7);
    ASSERT_EQ(min_pq.at(6), 4);
}

TEST_F(MinPriorityQueueTest, insert_singleton)
{
}

TEST_F(MinPriorityQueueTest, minimum)
{
}

TEST_F(MinPriorityQueueTest, extract_min)
{
}

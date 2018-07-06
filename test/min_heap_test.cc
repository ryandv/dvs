#include <stdio.h>
#include <vector>

#include "gtest/gtest.h"

#include "dvs/min_heap.h"

namespace {
    class MinHeapTest : public ::testing::Test {
        protected:
            virtual void SetUp()
            {
            }
    };
}

TEST_F(MinHeapTest, vec_min_heapify_left_subtree)
{
    std::vector<int> h = { 3, 1, 2 };
    min_heapify_vec(3, h, 0);
    ASSERT_EQ(h.at(0), 1);
    ASSERT_EQ(h.at(1), 3);
    ASSERT_EQ(h.at(2), 2);
}

TEST_F(MinHeapTest, vec_min_heapify_vec_right)
{
    std::vector<int> h = { 3, 2, 1 };
    min_heapify_vec(3, h, 0);
    ASSERT_EQ(h.at(0), 1);
    ASSERT_EQ(h.at(1), 2);
    ASSERT_EQ(h.at(2), 3);
}

TEST_F(MinHeapTest, vec_min_heapify_vec_recursive)
{
    std::vector<int> h = { 10, 1, 999, 2, 3 };
    min_heapify_vec(4, h, 0);
    ASSERT_EQ(h.at(0), 1);
    ASSERT_EQ(h.at(1), 2);
    ASSERT_EQ(h.at(2), 999);
    ASSERT_EQ(h.at(3), 10);
    ASSERT_EQ(h.at(4), 3);
}

TEST_F(MinHeapTest, vec_build_min_heap_singleton)
{
    std::vector<int> input = { 1 };
    Heap h = build_min_heap(1, input);
    ASSERT_EQ(h.at(0), 1);
}

TEST_F(MinHeapTest, vec_build_complete_min_heap)
{
    std::vector<int> input = { 5, 3, 1 };
    Heap h = build_min_heap(3, input);
    ASSERT_EQ(h.at(0), 1);
    ASSERT_EQ(h.at(1), 3);
    ASSERT_EQ(h.at(2), 5);
}

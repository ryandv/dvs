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

TEST_F(MinHeapTest, vec_build_min_heap_left_subtree)
{
    std::vector<int> h = { 3, 1, 2 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 3);
    ASSERT_EQ(heap.at(2), 2);
}

TEST_F(MinHeapTest, vec_build_min_heap_right_subtree)
{
    std::vector<int> h = { 3, 2, 1 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 2);
    ASSERT_EQ(heap.at(2), 3);
}

TEST_F(MinHeapTest, vec_build_min_heap_recursive)
{
    std::vector<int> h = { 10, 1, 999, 2, 3 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 2);
    ASSERT_EQ(heap.at(2), 999);
    ASSERT_EQ(heap.at(3), 10);
    ASSERT_EQ(heap.at(4), 3);
}

TEST_F(MinHeapTest, vec_build_min_heap_singleton)
{
    std::vector<int> h = { 1 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
}

TEST_F(MinHeapTest, vec_build_complete_min_heap)
{
    std::vector<int> h = { 5, 3, 1 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 3);
    ASSERT_EQ(heap.at(2), 5);
}

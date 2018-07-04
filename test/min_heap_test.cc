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

TEST_F(MinHeapTest, min_heapify_left_subtree)
{
    int h[] = { 3, 1, 2 };
    min_heapify_array(3, &h[0], 0);
    ASSERT_EQ(h[0], 1);
    ASSERT_EQ(h[1], 3);
    ASSERT_EQ(h[2], 2);
}

TEST_F(MinHeapTest, min_heapify_array_right)
{
    int h[] = { 3, 2, 1 };
    min_heapify_array(3, &h[0], 0);
    ASSERT_EQ(h[0], 1);
    ASSERT_EQ(h[1], 2);
    ASSERT_EQ(h[2], 3);
}

TEST_F(MinHeapTest, min_heapify_array_recursive)
{
    int h[] = { 10, 1, 999, 2, 3 };
    min_heapify_array(4, &h[0], 0);
    ASSERT_EQ(h[0], 1);
    ASSERT_EQ(h[1], 2);
    ASSERT_EQ(h[2], 999);
    ASSERT_EQ(h[3], 10);
    ASSERT_EQ(h[4], 3);
}

TEST_F(MinHeapTest, build_min_heap_singleton)
{
    int input[] = { 1 };
    int *built_heap = build_min_heap(1, &input[0]);
    ASSERT_EQ(built_heap[0], 1);
    free(built_heap);
}

TEST_F(MinHeapTest, build_complete_min_heap)
{
    int input[] = { 5, 3, 1 };
    int *built_heap = build_min_heap(3, &input[0]);
    ASSERT_EQ(built_heap[0], 1);
    ASSERT_EQ(built_heap[1], 3);
    ASSERT_EQ(built_heap[2], 5);
    free(built_heap);
}

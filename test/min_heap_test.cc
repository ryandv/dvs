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

TEST_F(MinHeapTest, build_min_heap_left_subtree)
{
    std::vector<int> h = { 3, 1, 2 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 3);
    ASSERT_EQ(heap.at(2), 2);
}

TEST_F(MinHeapTest, build_min_heap_right_subtree)
{
    std::vector<int> h = { 3, 2, 1 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 2);
    ASSERT_EQ(heap.at(2), 3);
}

TEST_F(MinHeapTest, build_min_heap_recursive)
{
    std::vector<int> h = { 10, 1, 999, 2, 3 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 2);
    ASSERT_EQ(heap.at(2), 999);
    ASSERT_EQ(heap.at(3), 10);
    ASSERT_EQ(heap.at(4), 3);
}

TEST_F(MinHeapTest, build_min_heap_singleton)
{
    std::vector<int> h = { 1 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
}

TEST_F(MinHeapTest, build_full_min_heap)
{
    std::vector<int> h = { 5, 3, 1 };
    Heap heap = Heap(h);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 3);
    ASSERT_EQ(heap.at(2), 5);
}

TEST_F(MinHeapTest, set_key_singleton)
{
    std::vector<int> min_pq = { 100 };
    set_key(min_pq, 0, 1);
    ASSERT_EQ(min_pq.at(0), 1);
}


TEST_F(MinHeapTest, set_key_raises_if_new_key_is_greater_than_current)
{
    std::vector<int> min_pq = { 1 };
    ASSERT_DEATH(set_key(min_pq, 0, 100), "Assertion `k <= pq_as_vec.at\\(i\\)' failed");
}

TEST_F(MinHeapTest, set_key_recursive_left_subtree)
{
    std::vector<int> min_pq = { 2, 3, 4, 5, 6 };
    set_key(min_pq, 4, 1);
    ASSERT_EQ(min_pq.at(0), 1);
    ASSERT_EQ(min_pq.at(1), 2);
    ASSERT_EQ(min_pq.at(2), 4);
    ASSERT_EQ(min_pq.at(3), 5);
    ASSERT_EQ(min_pq.at(4), 3);
}

TEST_F(MinHeapTest, set_key_recursive_right_subtree)
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

TEST_F(MinHeapTest, insert_singleton)
{
}

TEST_F(MinHeapTest, minimum)
{
}

TEST_F(MinHeapTest, extract_min)
{
}

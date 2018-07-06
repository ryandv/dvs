#include <stdio.h>
#include <stdexcept>
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

TEST_F(MinHeapTest, build_empty_min_heap)
{
    Heap<int> heap;
    ASSERT_EQ(heap.size(), 0);
    EXPECT_THROW(heap.at(0), std::out_of_range);
}

TEST_F(MinHeapTest, build_min_heap_left_subtree)
{
    Heap heap = Heap(std::vector<int> { 3, 1, 2 });
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 3);
    ASSERT_EQ(heap.at(2), 2);
}

TEST_F(MinHeapTest, build_min_heap_right_subtree)
{
    Heap heap = Heap(std::vector<int> { 3, 2, 1 });
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 2);
    ASSERT_EQ(heap.at(2), 3);
}

TEST_F(MinHeapTest, build_min_heap_recursive)
{
    Heap heap = Heap(std::vector<int> { 10, 1, 999, 2, 3 });
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 2);
    ASSERT_EQ(heap.at(2), 999);
    ASSERT_EQ(heap.at(3), 10);
    ASSERT_EQ(heap.at(4), 3);
}

TEST_F(MinHeapTest, build_min_heap_singleton)
{
    Heap heap = Heap(std::vector<int> { 1 });
    ASSERT_EQ(heap.at(0), 1);
}

TEST_F(MinHeapTest, build_full_min_heap)
{
    Heap heap = Heap(std::vector<int> { 5, 3, 1 });
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 3);
    ASSERT_EQ(heap.at(2), 5);
}

TEST_F(MinHeapTest, set_key_singleton)
{
    Heap heap = Heap(std::vector<int> { 100 });
    heap.set_key(0, 1);
    ASSERT_EQ(heap.at(0), 1);
}


TEST_F(MinHeapTest, set_key_raises_if_new_key_is_greater_than_current)
{
    Heap heap = Heap(std::vector<int> { 1 });
    ASSERT_DEATH(heap.set_key(0, 100), "Assertion `k <= heap_vec.at\\(i\\)' failed");
}

TEST_F(MinHeapTest, set_key_recursive_left_subtree)
{
    Heap heap = Heap(std::vector<int> { 2, 3, 4, 5, 6 });
    heap.set_key(4, 1);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 2);
    ASSERT_EQ(heap.at(2), 4);
    ASSERT_EQ(heap.at(3), 5);
    ASSERT_EQ(heap.at(4), 3);
}

TEST_F(MinHeapTest, set_key_recursive_right_subtree)
{
    Heap heap = Heap(std::vector<int> { 2, 3, 4, 5, 6, 7, 8 });
    heap.set_key(6, 1);
    ASSERT_EQ(heap.at(0), 1);
    ASSERT_EQ(heap.at(1), 3);
    ASSERT_EQ(heap.at(2), 2);
    ASSERT_EQ(heap.at(3), 5);
    ASSERT_EQ(heap.at(4), 6);
    ASSERT_EQ(heap.at(5), 7);
    ASSERT_EQ(heap.at(6), 4);
}

TEST_F(MinHeapTest, insert_singleton)
{
    Heap<int> heap;
    heap.insert(42);
    ASSERT_EQ(heap.at(0), 42);
    ASSERT_EQ(heap.size(), 1);
}

TEST_F(MinHeapTest, minimum)
{
    Heap heap = Heap(std::vector<int> { 5, 4, 3, 2, 1 });
    int min = heap.min();
    ASSERT_EQ(min, 1);
}

TEST_F(MinHeapTest, extract_min)
{
}

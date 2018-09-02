#include <stdio.h>
#include <stdexcept>
#include <vector>

#include "gtest/gtest.h"

#include "dvs/doubly_linked_list.h"

namespace {
    class DoublyLinkedListTest : public ::testing::Test {
        protected:
            virtual void SetUp()
            {
            }
    };
}

TEST_F(DoublyLinkedListTest, build_empty_linked_list)
{
    DoublyLinkedList<int> l;
    ASSERT_EQ(l.size(), 0);
}

TEST_F(DoublyLinkedListTest, insert_at_head_of_linked_list)
{
    DoublyLinkedList<int> l;
    l.insert(1);
    ASSERT_EQ(l.size(), 1);
    ASSERT_EQ(l.head().value().data(), 1);
}

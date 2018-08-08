#include <stdio.h>
#include <stdexcept>
#include <vector>

#include "gtest/gtest.h"

#include "dvs/graph.h"

namespace {
    class GraphTest : public ::testing::Test {
        protected:
            virtual void SetUp()
            {
            }
    };
}

TEST_F(GraphTest, build_empty_graph)
{
    Graph<int> graph;
    ASSERT_EQ(graph.get_value(), std::optional<int>());
    ASSERT_EQ(graph.get_vertices().size(), 0);
    ASSERT_EQ(graph.number_of_vertices(), 0);
}

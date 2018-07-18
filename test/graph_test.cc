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
    ASSERT_EQ(graph.size(), 0);
}

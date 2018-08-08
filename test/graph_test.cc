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
    ASSERT_EQ(graph.number_of_vertices(), 0);
}

TEST_F(GraphTest, build_non_empty_graph)
{
    Graph<int>::GraphVertex node_1(1, 1);
    Graph<int>::GraphVertex node_2(2, 2);
    Graph<int>::GraphVertex node_3(3, 3);
    std::pair<int, int> e_1_2(1, 2);
    std::pair<int, int> e_2_3(2, 3);
    std::pair<int, int> e_3_1(3, 1);
    std::vector<Graph<int>::GraphVertex> vertices { node_1, node_2, node_3 };
    std::vector<std::pair<int, int>> edges { e_1_2, e_2_3, e_3_1 };
    Graph<int> g(vertices, edges);

    ASSERT_EQ(g.number_of_vertices(), 3);
}

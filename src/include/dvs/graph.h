#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <memory>
#include <optional>
#include <vector>

template <typename T>
class Graph {
    public:
        class GraphVertex
        {
            public:
            GraphVertex() : key(-1)
                        , value(std::optional<T>())
            {
            }

            GraphVertex(int key, T value) : key(key)
                                        , value(std::optional<T>(value))
            {
            }

            private:

            int key;
            std::optional<T> value;
        };

    Graph() : vertices (std::vector<GraphVertex>())
            , edges (std::vector<std::pair<int, int>>())
    {
    }

    Graph(std::vector<GraphVertex> vertices, std::vector<std::pair<int, int>> edges) : vertices (vertices)
                                                                                     , edges (edges)
    {
    }

    const std::size_t number_of_vertices()
    {
        return vertices.size();
    }

    const std::vector<GraphVertex> &get_vertices()
    {
        return vertices;
    }

    private:
        std::vector<std::pair<int, int>> edges;
        std::vector<GraphVertex> vertices;
};

#endif

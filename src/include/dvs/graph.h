#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <optional>
#include <vector>

template <typename T>
class Graph {
    public:
        Graph() : value(std::optional<T>())
                , neighbours (std::vector<T>())
    {
    }

    const std::size_t number_of_vertices()
    {
        return neighbours.size();
    }

    const std::optional<T> &get_value()
    {
        return value;
    }

    private:
        std::optional<T> value;
        std::vector<T> neighbours;
};

#endif

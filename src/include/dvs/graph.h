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

    std::size_t size()
    {
        return 0;
    }

    private:
        std::optional<T> value;
        std::vector<T> neighbours;
};

#endif

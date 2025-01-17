#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>
#include <iostream>

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;
        int numVertices;
        int numEdges;
        bool isDirected;

    public:
        Graph() : numVertices(0), numEdges(0), isDirected(false) {}

        void loadGraph(const std::vector<std::vector<int>>& matrix);

        void printGraph() const;

        const std::vector<std::vector<int>>& getAdjMatrix() const;

        int getNumVertices() const;

        int getNumEdges() const;

        bool isDirectedGraph() const;
    };
}

#endif // GRAPH_HPP
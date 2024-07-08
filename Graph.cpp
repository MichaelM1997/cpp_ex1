#include "Graph.hpp"

namespace ariel {

    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix.size() != matrix[0].size()) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        adjMatrix = matrix;
        numVertices = matrix.size();
        numEdges = 0;
        isDirected = false;

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] != 0) {
                    numEdges++;
                    if (adjMatrix[i][j] != adjMatrix[j][i]) {
                        isDirected = true;
                    }
                }
            }
        }

        if (!isDirected) {
            numEdges /= 2;
        }
    }

    void Graph::printGraph() const {
        std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << std::endl;
    }

    const std::vector<std::vector<int>>& Graph::getAdjMatrix() const {
        return adjMatrix;
    }

    int Graph::getNumVertices() const {
        return numVertices;
    }

    int Graph::getNumEdges() const {
        return numEdges;
    }

    bool Graph::isDirectedGraph() const {
        return isDirected;
    }


}
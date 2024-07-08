#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#pragma once
#include "Graph.hpp"
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <climits>


namespace ariel {

    class Algorithms{

    private:
        static void bfs(const Graph& g, size_t start, std::vector<bool>& visited);
        static bool dfs(const std::vector<std::vector<int>>& adjMatrix, size_t u, std::vector<bool>& visited, std::vector<bool>& inStack);
        static bool bfsBipartite(const Graph& g, size_t start, std::vector<int>& color, std::vector<int>& setA, std::vector<int>& setB);
        static bool bellmanFord(const Graph& g, std::vector<int>& dist);

    public:
        static std::string isConnected(const Graph& g);

        static std::string shortestPath(Graph& g, int start_i, int end_i);

        static std::string isContainsCycle(Graph& g);

        static std::string isBipartite(Graph& g);

        static std::string negativeCycle(Graph& g);
    };
}
#endif
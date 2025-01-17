#include "Algorithms.hpp"

namespace ariel {

    static void bfs(const Graph& g, size_t start, std::vector<int>& dist, std::vector<int>& prev) {
        size_t numVertices = g.getNumVertices();
        std::queue<size_t> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            size_t v = q.front();
            q.pop();

            for (size_t i = 0; i < numVertices; ++i) {
                if (g.getAdjMatrix()[v][i] > 0 && dist[i] == INT_MAX) {
                    dist[i] = dist[v] + 1;
                    prev[i] = v;
                    q.push(i);
                }
            }
        }
    }

    static bool bfsBipartite(const Graph& g, size_t start, std::vector<int>& color, std::vector<int>& setA, std::vector<int>& setB) {
        std::queue<size_t> queue;
        queue.push(start);
        color[start] = 0;
        setA.push_back(start);

        while (!queue.empty()) {
            size_t curr = queue.front();
            queue.pop();

            for (size_t neighbor = 0; neighbor < g.getNumVertices(); neighbor++) {
                if (g.getAdjMatrix()[curr][neighbor] == 1) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[curr];
                        queue.push(neighbor);
                        (color[neighbor] == 0 ? setA : setB).push_back(neighbor);
                    } else if (color[neighbor] == color[curr]) {
                        return false; // Not bipartite
                    }
                }
            }
        }
        return true;
    }

    static bool dfs(const std::vector<std::vector<int>>& adjMatrix, size_t u, std::vector<bool>& visited, std::vector<bool>& inStack) {
        visited[u] = true;
        inStack[u] = true;

        for (size_t v = 0; v < adjMatrix.size(); v++) {
            if (adjMatrix[u][v] != 0) { // If there is an edge between u and v
                if (!visited[v]) {
                    if (dfs(adjMatrix, v, visited, inStack)) {
                        return true; // Cycle detected in deeper recursion
                    }
                } else if (inStack[v]) {
                    return true; // Cycle detected
                }
            }
        }
        inStack[u] = false; // Remove the vertex from the current path
        return false;
    }

    static bool bellmanFord(const Graph& g, std::vector<int>& dist) {
        size_t numVertices = g.getNumVertices();
        const std::vector<std::vector<int>>& adjMatrix = g.getAdjMatrix();

        // Initialize distances
        dist[0] = 0;

        // Relax edges V-1 times
        for (size_t k = 0; k < numVertices - 1; ++k) {
            for (size_t u = 0; u < numVertices; ++u) {
                for (size_t v = 0; v < numVertices; ++v) {
                    if (adjMatrix[u][v] != 0 && dist[u] != INT_MAX &&
                        dist[u] + adjMatrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adjMatrix[u][v];
                    }
                }
            }
        }

        // Check for negative-weight cycles
        for (size_t u = 0; u < numVertices; ++u) {
            for (size_t v = 0; v < numVertices; ++v) {
                if (adjMatrix[u][v] != 0 && dist[u] != INT_MAX &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    return true; // Negative cycle detected
                }
            }
        }

        return false; // No negative cycle
    }

    std::string Algorithms::isConnected(const Graph& g) {
        size_t numVertices = g.getNumVertices();
        if (numVertices == 0)
            return 0;

        std::vector<int> dist(numVertices, INT_MAX);
        std::vector<int> prev(numVertices, -1);

        // Start BFS from the first vertex
        ::ariel::bfs(g, 0, dist, prev);

        // Check if all vertices are reachable
        for (size_t i = 0; i < numVertices; ++i) {
            if (dist[i] == INT_MAX)
                return "false";
        }
        return "true";
    }

    static std::string shortestPath(const Graph& g, int start_i, int end_i) {
        size_t start = static_cast<size_t>(start_i);
        size_t end = static_cast<size_t>(end_i);
        size_t numVertices = g.getNumVertices();

        if (start >= numVertices || end >= numVertices) {
            throw std::out_of_range("Invalid start or end vertex");
        }

        std::vector<int> dist(numVertices, INT_MAX);
        std::vector<int> prev(numVertices, -1);

        bfs(g, start, dist, prev);

        if (dist[end] == INT_MAX) {
            return "-1"; // No path
        }

        // Reconstruct the path
        std::vector<int> path;
        for (int at = end; at != -1; at = prev[static_cast<size_t>(at)]) {
            path.push_back(at);
        }
        std::reverse(path.begin(), path.end());

        // Format the path as a string
        std::ostringstream oss;
        for (size_t i = 0; i < path.size(); ++i) {
            oss << path[i];
            if (i < path.size() - 1) {
                oss << "->";
            }
        }
        return oss.str();
    }

    static std::string isContainsCycle(const Graph& g) {
        const std::vector<std::vector<int>>& adjMatrix = g.getAdjMatrix();
        size_t n = adjMatrix.size();
        std::vector<bool> visited(n, false);
        std::vector<bool> inStack(n, false);

        for (size_t u = 0; u < n; u++) {
            if (!visited[u]) {
                if (dfs(adjMatrix, u, visited, inStack)) {
                    return "true";
                }
            }
        }

        return "false";
    }

    static std::string isBipartite(const Graph& g) {
        size_t numVertices = g.getNumVertices();
        if (numVertices <= 1) {
            return "The graph is bipartite: A={}, B={}";
        }

        std::vector<int> color(numVertices, -1);
        std::vector<int> setA, setB;

        for (size_t node = 0; node < numVertices; node++) {
            if (color[node] == -1) {
                if (!bfsBipartite(g, node, color, setA, setB)) {
                    return "0";
                }
            }
        }

        // Construct the output string
        std::ostringstream oss;
        oss << "The graph is bipartite: A={";
        for (size_t i = 0; i < setA.size(); ++i) {
            oss << setA[i] << (i != setA.size() - 1 ? ", " : "");
        }
        oss << "}, B={";
        for (size_t i = 0; i < setB.size(); ++i) {
            oss << setB[i] << (i != setB.size() - 1 ? ", " : "");
        }
        oss << "}";
        return oss.str();
    }

    static std::string negativeCycle(const Graph& g) {
        std::vector<int> dist(g.getNumVertices(), INT_MAX);
        bool hasNegativeCycle = bellmanFord(g, dist);
        return hasNegativeCycle ? "true" : "false";
    }




};




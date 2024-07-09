# מטלה 1 - גרפים (Classes and Namespaces)

המטרה שלכם במטלה הזאת היא ליצור מחלקה שמייצגת גרף ולממש אלגוריתמים על הגרפים (זה הזמן להזכר בקורס אלגוריתמים 1).

במטלה הזאת הייצוג של הגרף שלכם יתבצע בעזרת מטריצת שכנויות - https://he.wikipedia.org/wiki/%D7%9E%D7%98%D7%A8%D7%99%D7%A6%D7%AA_%D7%A9%D7%9B%D7%A0%D7%95%D7%AA.

הגרף יכול להיות גרף מכוון ולא מכוון וגם גרף ממושקל. מטריצת השכנויות חייבת להיות מטריצה ריבועית.

עליכם לכתוב את הקבצים הבאים:

```
Graph.cpp
Algorithms.cpp
```

הקובץ `Graph.cpp` מכיל מחלקה המייצגת גרף.
המחלקה מכילה את הפעולות `loadGraph` המקבלת מטריצת שכנויות וטוענת אותה לתוך הגרף ו-`printGraph` שמדפיסה את הייצוג של הגרף (הפורמט לבחירתכם, ראו דוגמה ב-`Demo.cpp`).

הקובץ `Algorithms.cpp` מכיל מימושים לאלגוריתמים על גרפים. ביניהם:

- `isConnected(g)` - האלגוריתם מקבל גרף ומחזיר 1 אם הגרף קשיר (אחרת מחזיר 0).
- `shortestPath(g,start,end)` - האלגוריתם מקבל גרף, קודקוד התחלה וקודקוד סיום ומחזיר את המסלול הקל ביותר (במקרה שהגרף לא ממושקל - הקצר ביותר) בין שני הקודקודים. במידה ואין מסלול כזה, האלגוריתם יחזיר -1.
- `isContainsCycle(g)` - האלגוריתם מקבל גרף ומדפיס מעגל כלשהו. אם לא קיים מעגל בגרף, האלגוריתם יחזיר 0.
- `isBipartite(g)` - האלגוריתם מקבל גרף ומחזיר את החלוקה של הגרף לגרף דו-צדדי. אם אי אפשר לחלק את הגרף, האלגוריתם יחזיר 0.
- `negativeCycle(g)` - האלגוריתם מקבל גרף ומוצא מעגל שלילי (כלומר מעגל שסכום המשקלים של הצלעות שלילי). אם לא קיים מעגל כזה, האלגוריתם ידפיס שלא קיים מעגל שלילי.

הקובץ `Demo.cpp` מכיל דוגמאות של קלטים ופלטים.
עליכם לכתוב בתחילת כל קובץ את מספר תעודת הזהות שלכם ואת המייל. כמו כן, בנוסף לקבצים של המטלה אתם נדרשים להגיש גם קובץ README המתאר את אופן המימוש ואת החלוקה שביצעתם בקוד (סוג של מדריך משתמש). אי עמידה בהנחיות תגרור הפחתה בציון. בהצלחה!


# Graph Algorithms

This project implements a Graph class and various graph algorithms in C++.

## Table of Contents
- [Introduction](#introduction)
- [Graph Class](#graph-class)
- [Algorithms Class](#algorithms-class)
- [Usage](#usage)
- [File Structure](#file-structure)

## Introduction
The Graph Algorithms project provides a set of classes and functions to work with graphs and perform various graph-related operations. It includes a Graph class to represent a graph and an Algorithms class that contains static methods for graph algorithms.

## Graph Class
The `Graph` class represents a graph using an adjacency matrix. It provides the following functionality:
- `loadGraph(const std::vector<std::vector<int>>& matrix)`: Loads a graph from an adjacency matrix.
- `printGraph() const`: Prints the number of vertices and edges in the graph.
- `getAdjMatrix() const`: Returns the adjacency matrix of the graph.
- `getNumVertices() const`: Returns the number of vertices in the graph.
- `getNumEdges() const`: Returns the number of edges in the graph.
- `isDirectedGraph() const`: Checks if the graph is directed.

## Algorithms Class
The `Algorithms` class contains static methods for various graph algorithms:
- `bfs(const Graph& g, size_t start, std::vector<int>& dist, std::vector<int>& prev)`: Performs Breadth-First Search (BFS) on the graph starting from a given vertex.
- `dfs(const std::vector<std::vector<int>>& adjMatrix, size_t u, std::vector<bool>& visited, std::vector<bool>& inStack)`: Performs Depth-First Search (DFS) on the graph to detect cycles.
- `bfsBipartite(const Graph& g, size_t start, std::vector<int>& color, std::vector<int>& setA, std::vector<int>& setB)`: Performs BFS to check if the graph is bipartite.
- `bellmanFord(const Graph& g, std::vector<int>& dist)`: Implements the Bellman-Ford algorithm to find the shortest paths from a source vertex to all other vertices.
- `isConnected(const Graph& g)`: Checks if the graph is connected.
- `shortestPath(const Graph& g, int start_i, int end_i)`: Finds the shortest path between two vertices in the graph.
- `isContainsCycle(const Graph& g)`: Checks if the graph contains a cycle.
- `isBipartite(const Graph& g)`: Checks if the graph is bipartite and returns the bipartition sets.

## Usage
To use the Graph Algorithms library:
1. Include the necessary header files: `Graph.hpp` and `Algorithms.hpp`.
2. Create a `Graph` object and load the graph using the `loadGraph` function, providing an adjacency matrix.
3. Use the methods in the `Algorithms` class to perform various graph operations on the `Graph` object.

## File Structure
- `Graph.hpp`: Header file containing the declaration of the `Graph` class.
- `Graph.cpp`: Implementation file for the `Graph` class.
- `Algorithms.hpp`: Header file containing the declaration of the `Algorithms` class.
- `Algorithms.cpp`: Implementation file for the `Algorithms` class.
  

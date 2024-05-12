# Graph Algorithms Library

This library provides implementations of various graph algorithms for tasks such as checking is graph connected, finding shortest paths for vertices, detecting the existance of cycles and negative cycles, and determining whether a graph is bipartite.

## Implemented Algorithms

### 1. isConnected(Graph)

**Description:**
This function checks whether the given graph is connected, meaning that there exists a path between every pair of vertices in the graph.

**Implementation:**
- The function starts by checking if the graph has 0 or 1 vertices. If so, it returns `true` because a graph with 0 or 1 vertices is considered connected.
- If the graph has more than 1 vertex, it performs a Depth-First Search (DFS) traversal starting from the first vertex.
- During the DFS traversal, it marks each visited vertex.
- After the traversal, if all vertices were visited, it indicates that the graph is connected, and the function returns `true`.
- Otherwise, if there are unvisited vertices, it returns `false`.

### 2. shortestPath(Graph, start, end)

**Description:**
This function finds the shortest path between two given vertices in the graph, using the Bellman-Ford algorithm.

**Implementation:**
- The function first checks if the graph has 0 or 1 vertices. If so, it returns `-1` because there is no meaningful path.
- It then applies the Bellman-Ford algorithm starting from the specified start vertex.
- The algorithm iterates \(V-1\) times, relaxing all edges in each iteration to find the shortest paths.
- After the iterations, it checks for negative cycles. If any negative cycles are found, it returns `-1` to indicate that there is no meaningful shortest path due to the negative cycle.
- If no negative cycles are found, it constructs the shortest path from the start vertex to the end vertex using the path vector obtained from the Bellman-Ford algorithm.
- The function returns the shortest path as a string, or `-1` if no path exists.

### 3. isContainsCycle(Graph)

**Description:**
This function checks whether the given graph contains any cycles.

**Implementation:**
- The function applies Depth-First Search (DFS) starting from each vertex in the graph.
- During the DFS traversal, it maintains a parent array to keep track of the parent vertex for each visited vertex.
- If it encounters a visited vertex that is not the parent of the current vertex, it indicates the presence of a cycle.
- After DFS traversal from all vertices, if no cycles are found, the function returns `0`. Otherwise, it returns a string representing the cycle.

### 4. isBipartite(Graph)

**Description:**
This function checks whether the given graph is bipartite, meaning that its vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent.

**Implementation:**
- The function applies Breadth-First Search (BFS) starting from each vertex in the graph.
- During the BFS traversal, it assigns colors (e.g., "RED" and "BLUE") to the vertices in alternating layers.
- If it encounters adjacent vertices with the same color, it indicates that the graph is not bipartite.
- After BFS traversal from all vertices, if no conflicts are found, the function returns a string representing the bipartition of the graph.

### 5. negativeCycle(Graph)

**Description:**
This function checks for the presence of a negative cycle in the graph.

**Implementation:**
- The function applies the Bellman-Ford algorithm starting from a specified start vertex.
- It iterates \(V-1\) times, relaxing all edges in each iteration to find the shortest paths.
- After the iterations, it checks for additional relaxation steps. If any edges are relaxed in the additional step, it indicates the presence of a negative cycle.
- If a negative cycle is found, the function returns a string indicating its presence. Otherwise, it returns a string indicating its absence.

## Code Structure

The codebase is divided into two main files:

1. **Graph.hpp / Graph.cpp**
   - Contains the implementation of the `Graph` class.
   - Provides functionalities to load adjacency matrices, print graphs, get weights of edges, check for negative cycles, and set cycle flags.

2. **Algorithms.hpp / Algorithms.cpp**
   - Implements various graph algorithms like checking if the graph is connected, shortest path finding, cycle and negative cycle detection, and bipartiteness checking.
   - Utilizes Bellman-Ford algorithm for shortest path, Depth-First Search (DFS) for cycle detection, and Breadth-First Search (BFS) for bipartiteness checking.

## Usage

To use the library, follow these steps:

1. Include the necessary header files in your project:

   ```cpp
   #include "Graph.hpp"
   #include "Algorithms.hpp"
   ```

2. Create a `Graph` object and load the graph data:

   ```cpp
   vector<vector<int>> adjacencyMatrix = { /* Your graph data here */ };
   Graph g(adjacencyMatrix);
   ```

3. Use the provided algorithms to perform graph operations:

   ```cpp
   bool connected = Algorithms::isConnected(g);
   string shortestPath = Algorithms::shortestPath(g, startVertex, endVertex);
   string cycle = Algorithms::isContainsCycle(g);
   string bipartite = Algorithms::isBipartite(g);
   string negCycle = Algorithms::negativeCycle(g);
   ```

4. Analyze the results as needed for the application.

#include "graph.h"
// Description

// Write a function that counts how many nodes are isolated.
// A node is isolated if it has no edges connected to it.
// // The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.




int count_isolated(Graph* g) {
    int isolated_count = 0;

    // Iterate through every node (row)
    for (int u = 0; u < MAX_NODES; u++) {
        int has_edge = 0; // Flag to track if we find an edge for node u

        // Check all potential connections (columns) for node u
        for (int v = 0; v < MAX_NODES; v++) {
            if (g->adj[u][v] == 1) {
                has_edge = 1;
                break; // Optimization: We found an edge, no need to check the rest of the row
            }
        }

        // If the flag is still 0, the node has no edges
        if (has_edge == 0) {
            isolated_count++;
        }
    }

    return isolated_count;
   
}















// Tip: In the adjacency matrix, that means the entire row for that node contains only 0s.

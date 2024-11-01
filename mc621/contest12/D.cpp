#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform DFS and return the size of the connected component
int dfs(int node, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[node] = true;
    int componentSize = 1; // Start with the current node

    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[node][i] == 1 && !visited[i]) { // If there's an edge and the node is unvisited
            componentSize += dfs(i, adjMatrix, visited); // Recursively visit all connected nodes
        }
    }
    return componentSize;
}

// Function to find the largest connected component in the graph
int findLargestComponent(vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<bool> visited(n, false);
    int largestComponentSize = 0;k

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int componentSize = dfs(i, adjMatrix, visited);
            largestComponentSize = max(largestComponentSize, componentSize);
        }
    }

    return largestComponentSize;
}

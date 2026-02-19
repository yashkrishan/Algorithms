/*
Breadth-First Search (BFS) for Graph Traversal

This implementation provides BFS traversal functionality for a graph represented
as an adjacency list. It includes methods for:
- Performing BFS traversal from a source node
- Validating graph input
- Counting visited nodes
- Checking node reachability
- Finding shortest path length between nodes

Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges
Space Complexity: O(V) for visited tracking and queue storage
*/

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * Performs breadth-first search traversal on a graph represented as adjacency list.
     * @param start Source node index for BFS traversal
     * @param graph Adjacency list where graph[i] contains neighbors of node i
     * @return vector<int> - Nodes visited level by level from start node
     *         Returns empty vector if graph is empty or start is out of bounds
     */
    vector<int> bfs(int start, vector<vector<int>>& graph);
    
    /**
     * Validates that the graph input is properly formatted and safe to process.
     * @param graph Adjacency list to validate
     * @return bool - True if graph is non-empty and properly structured
     */
    bool validateGraphInput(vector<vector<int>>& graph);
    
    /**
     * Returns the count of nodes visited during BFS traversal.
     * @param result BFS traversal result
     * @return int - Number of nodes in the result vector
     */
    int getVisitedCount(vector<int>& result);
    
    /**
     * Checks if a target node is reachable from the start node using BFS.
     * @param start Source node index
     * @param target Target node index to check reachability
     * @param graph Adjacency list representing the graph
     * @return bool - True if target can be reached from start via BFS
     */
    bool isNodeReachable(int start, int target, vector<vector<int>>& graph);
    
    /**
     * Returns the shortest path length (number of edges) from start to target using BFS.
     * @param start Source node index
     * @param target Target node index
     * @param graph Adjacency list representing the graph
     * @return int - Number of edges in shortest path, or -1 if unreachable
     */
    int getShortestPathLength(int start, int target, vector<vector<int>>& graph);
};

// Method implementations

vector<int> Solution::bfs(int start, vector<vector<int>>& graph) {
    vector<int> visitedNodes;
    
    // Validate input
    if (!validateGraphInput(graph)) {
        return visitedNodes;
    }
    
    int n = graph.size();
    if (start < 0 || start >= n) {
        return visitedNodes;
    }
    
    // Track visited nodes
    vector<bool> visited(n, false);
    queue<int> q;
    
    // Start BFS from the source node
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visitedNodes.push_back(current);
        
        // Explore all neighbors
        for (int neighbor : graph[current]) {
            if (neighbor >= 0 && neighbor < n && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return visitedNodes;
}

bool Solution::validateGraphInput(vector<vector<int>>& graph) {
    // Check if graph is empty
    if (graph.empty()) {
        return false;
    }
    
    int n = graph.size();
    
    // Validate each node's adjacency list
    for (int i = 0; i < n; i++) {
        for (int neighbor : graph[i]) {
            // Check if neighbor index is valid
            if (neighbor < 0 || neighbor >= n) {
                return false;
            }
        }
    }
    
    return true;
}

int Solution::getVisitedCount(vector<int>& result) {
    return static_cast<int>(result.size());
}

bool Solution::isNodeReachable(int start, int target, vector<vector<int>>& graph) {
    // Validate input
    if (!validateGraphInput(graph)) {
        return false;
    }
    
    int n = graph.size();
    if (start < 0 || start >= n || target < 0 || target >= n) {
        return false;
    }
    
    // Special case: start equals target
    if (start == target) {
        return true;
    }
    
    // BFS to find target
    vector<bool> visited(n, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int neighbor : graph[current]) {
            if (neighbor == target) {
                return true;
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return false;
}

int Solution::getShortestPathLength(int start, int target, vector<vector<int>>& graph) {
    // Validate input
    if (!validateGraphInput(graph)) {
        return -1;
    }
    
    int n = graph.size();
    if (start < 0 || start >= n || target < 0 || target >= n) {
        return -1;
    }
    
    // Special case: start equals target
    if (start == target) {
        return 0;
    }
    
    // BFS to find shortest path
    vector<bool> visited(n, false);
    queue<pair<int, int>> q; // (node, distance)
    
    visited[start] = true;
    q.push({start, 0});
    
    while (!q.empty()) {
        auto [current, dist] = q.front();
        q.pop();
        
        for (int neighbor : graph[current]) {
            if (neighbor == target) {
                return dist + 1;
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }
    
    // Target not reachable
    return -1;
}

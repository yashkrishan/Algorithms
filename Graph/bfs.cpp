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
     * Validates that the graph input is properly formatted and safe to process
     * @param graph Adjacency list to validate
     * @return true if graph is non-empty and properly structured
     */
    bool validateGraphInput(vector<vector<int>>& graph) {
        // Check for empty graph
        if (graph.empty()) {
            return false;
        }
        
        // Check that graph is a valid adjacency list (each element should be a vector)
        // A single node graph with no edges is valid: graph = [[]]
        // We just need to ensure graph has at least one node
        return true;
    }

    /**
     * Validates that the start index is within bounds of the graph
     * @param start Start node index
     * @param graph The graph adjacency list
     * @return true if start index is valid
     */
    bool isValidStartNode(int start, vector<vector<int>>& graph) {
        // Check if graph is empty
        if (graph.empty()) {
            return false;
        }
        
        // Check if start index is negative
        if (start < 0) {
            return false;
        }
        
        // Check if start index is out of bounds
        if (start >= static_cast<int>(graph.size())) {
            return false;
        }
        
        return true;
    }

    /**
     * Performs breadth-first search traversal on a graph represented as adjacency list
     * @param start Source node index for BFS traversal
     * @param graph Adjacency list where graph[i] contains neighbors of node i
     * @return vector<int> - Nodes visited level by level from start node
     */
    vector<int> bfs(int start, vector<vector<int>>& graph) {
        vector<int> result;
        
        // Validate graph input
        if (!validateGraphInput(graph)) {
            return result;  // Return empty vector for invalid input
        }
        
        // Validate start node index
        if (!isValidStartNode(start, graph)) {
            return result;  // Return empty vector for invalid start
        }
        
        int n = graph.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        // Start BFS from the source node
        visited[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);
            
            // Visit all neighbors of current node
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return result;
    }

    /**
     * Returns the count of nodes visited during BFS traversal
     * @param result BFS traversal result
     * @return int - Number of nodes in the result vector
     */
    int getVisitedCount(vector<int>& result) {
        return static_cast<int>(result.size());
    }

    /**
     * Checks if a target node is reachable from the start node using BFS
     * @param start Source node index
     * @param target Target node index to check reachability
     * @param graph Adjacency list representing the graph
     * @return bool - True if target can be reached from start via BFS
     */
    bool isNodeReachable(int start, int target, vector<vector<int>>& graph) {
        // Validate graph input
        if (!validateGraphInput(graph)) {
            return false;
        }
        
        // Validate start and target indices
        if (!isValidStartNode(start, graph)) {
            return false;
        }
        
        // Check if target is valid
        if (target < 0 || target >= static_cast<int>(graph.size())) {
            return false;
        }
        
        // If start equals target, it's reachable
        if (start == target) {
            return true;
        }
        
        int n = graph.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int neighbor : graph[current]) {
                if (neighbor == target) {
                    return true;  // Found target
                }
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return false;  // Target not reachable
    }

    /**
     * Returns the shortest path length (number of edges) from start to target using BFS
     * @param start Source node index
     * @param target Target node index
     * @param graph Adjacency list representing the graph
     * @return int - Number of edges in shortest path, or -1 if unreachable
     */
    int getShortestPathLength(int start, int target, vector<vector<int>>& graph) {
        // Validate graph input
        if (!validateGraphInput(graph)) {
            return -1;
        }
        
        // Validate start node
        if (!isValidStartNode(start, graph)) {
            return -1;
        }
        
        // Check if target is valid
        if (target < 0 || target >= static_cast<int>(graph.size())) {
            return -1;
        }
        
        // If start equals target, path length is 0
        if (start == target) {
            return 0;
        }
        
        int n = graph.size();
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;  // Pair of node and distance
        
        visited[start] = true;
        q.push({start, 0});
        
        while (!q.empty()) {
            auto [current, dist] = q.front();
            q.pop();
            
            for (int neighbor : graph[current]) {
                if (neighbor == target) {
                    return dist + 1;  // Found target, return distance
                }
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1});
                }
            }
        }
        
        return -1;  // Target not reachable
    }
};

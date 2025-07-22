// Link: https://leetcode.com/problems/modify-graph-edge-weights/description
// Description
// You are given an
// undirected weighted
// connected
// graph containing
// n
// nodes labeled from
// 0
// to
// n - 1
// , and an integer array
// edges
// where
// edges[i] = [a
// i
// , b
// i
// , w
// i
// ]
// indicates that there is an edge between nodes
// a
// i
// and
// b
// i
// with weight
// w
// i
// .
// Some edges have a weight of
// -1
// (
// w
// i
// = -1
// ), while others have a
// positive
// weight (
// w
// i
// > 0
// ).
// Your task is to modify
// all edges
// with a weight of
// -1
// by assigning them
// positive integer values
// in the range
// [1, 2 * 10
// 9
// ]
// so that the
// shortest distance
// between the nodes
// source
// and
// destination
// becomes equal to an integer
// target
// . If there are
// multiple
// modifications
// that make the shortest distance between
// source
// and
// destination
// equal to
// target
// , any of them will be considered correct.
// Return
// an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from
// source
// to
// destination
// equal to
// target
// , or an
// empty array
// if it's impossible.
// Note:
// You are not allowed to modify the weights of edges with initial positive weights.
// Example 1:
// Input:
// n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
// Output:
// [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
// Explanation:
// The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
// Example 2:
// Input:
// n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
// Output:
// []
// Explanation:
// The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
// Example 3:
// Input:
// n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
// Output:
// [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
// Explanation:
// The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
// Constraints:
// 1 <= n <= 100
// 1 <= edges.length <= n * (n - 1) / 2
// edges[i].length == 3
// 0 <= a
// i
// , b
// i
// < n
// w
// i
// = -1
// or
// 1 <= w
// i
// <= 10
// 7
// a
// i
// != b
// i
// 0 <= source, destination < n
// source != destination
// 1 <= target <= 10
// 9
// The graph is connected, and there are no self-loops or repeated edges

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++) {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i);
            adjacencyList[nodeB].emplace_back(nodeA, i);
        }

        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        distances[source][0] = distances[source][1] = 0;

        runDijkstra(adjacencyList, edges, distances, source, 0, 0);
        int difference = target - distances[destination][0];
        if (difference < 0) return {}; 
        runDijkstra(adjacencyList, edges, distances, source, difference, 1);
        if (distances[destination][1] < target) return {}; 

        for (auto& edge : edges) {
            if (edge[2] == -1) edge[2] = 1;
        }
        return edges;
    }

private:
    void runDijkstra(const vector<vector<pair<int, int>>>& adjacencyList, vector<vector<int>>& edges, vector<vector<int>>& distances, int source, int difference, int run) {
        int n = adjacencyList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, source});
        distances[source][run] = 0;

        while (!priorityQueue.empty()) {
            auto [currentDistance, currentNode] = priorityQueue.top();
            priorityQueue.pop();

            if (currentDistance > distances[currentNode][run]) continue;

            for (auto& neighbor : adjacencyList[currentNode]) {
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                int weight = edges[edgeIndex][2];

                if (weight == -1) weight = 1; 

                if (run == 1 && edges[edgeIndex][2] == -1) {
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1];
                    if (newWeight > weight) {
                        edges[edgeIndex][2] = weight = newWeight;
                    }
                }

                if (distances[nextNode][run] > distances[currentNode][run] + weight) {
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};


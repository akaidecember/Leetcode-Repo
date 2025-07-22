// Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description
// Description
// You have a graph of
// n
// nodes. You are given an integer
// n
// and an array
// edges
// where
// edges[i] = [a
// i
// , b
// i
// ]
// indicates that there is an edge between
// a
// i
// and
// b
// i
// in the graph.
// Return
// the number of connected components in the graph
// .
// Example 1:
// Input:
// n = 5, edges = [[0,1],[1,2],[3,4]]
// Output:
// 2
// Example 2:
// Input:
// n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
// Output:
// 1
// Constraints:
// 1 <= n <= 2000
// 1 <= edges.length <= 5000
// edges[i].length == 2
// 0 <= a
// i
// <= b
// i
// < n
// a
// i
// != b
// i
// There are no repeated edges.

class Solution {
public:
    void bfs(int i, vector<vector<int>> &adj, vector<bool> &visit){
        queue<int> q;
        q.push(i);
        visit[i] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(const auto& nei : adj[node]){
                if(!visit[nei]){
                    q.push(nei);
                    visit[nei] = true;
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(2000, false);
        int ret = 0;
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                bfs(i ,adj, visit);
                ret++;
            }
        }
        return ret;
    }
};

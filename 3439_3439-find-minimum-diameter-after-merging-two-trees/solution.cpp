// Link: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description
// Description
// There exist two
// undirected
// trees with
// n
// and
// m
// nodes, numbered from
// 0
// to
// n - 1
// and from
// 0
// to
// m - 1
// , respectively. You are given two 2D integer arrays
// edges1
// and
// edges2
// of lengths
// n - 1
// and
// m - 1
// , respectively, where
// edges1[i] = [a
// i
// , b
// i
// ]
// indicates that there is an edge between nodes
// a
// i
// and
// b
// i
// in the first tree and
// edges2[i] = [u
// i
// , v
// i
// ]
// indicates that there is an edge between nodes
// u
// i
// and
// v
// i
// in the second tree.
// You must connect one node from the first tree with another node from the second tree with an edge.
// Return the
// minimum
// possible
// diameter
// of the resulting tree.
// The
// diameter
// of a tree is the length of the
// longest
// path between any two nodes in the tree.
// Example 1:
// Input:
// edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
// Output:
// 3
// Explanation:
// We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.
// Example 2:
// Input:
// edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
// Output:
// 5
// Explanation:
// We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.
// Constraints:
// 1 <= n, m <= 10
// 5
// edges1.length == n - 1
// edges2.length == m - 1
// edges1[i].length == edges2[i].length == 2
// edges1[i] = [a
// i
// , b
// i
// ]
// 0 <= a
// i
// , b
// i
// < n
// edges2[i] = [u
// i
// , v
// i
// ]
// 0 <= u
// i
// , v
// i
// < m
// The input is generated such that
// edges1
// and
// edges2
// represent valid trees.

class Solution {
public:
    void build(vector<vector<int>>& adj, vector<vector<int>>& edges, int n){
        for(const auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    }

    void get(pair<int, int> &p, vector<vector<int>> &adj, int node, int dis, vector<int> &vis){
        int d = p.second;
        vis[node] = 1;
        if(dis > d){
            p.second = dis;
            p.first = node;
        }
        for(auto it : adj[node]){
            if(!vis[it]){
                get(p, adj, it, dis + 1, vis);
            }
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        build(adj1, edges1, n);
        build(adj2, edges2, m);
        vector<int> vis(n);
        pair<int, int> p1 = {-1, INT_MIN};
        get(p1, adj1, 0, 0, vis);
        vis = vector<int>(n, 0);
        pair<int, int> p2 = {-1, INT_MIN};
        get(p2, adj1, p1.first, 0, vis);
        int d1 = p2.second;
        p1 = {-1, INT_MIN};
        vis = vector<int>(m, 0);
        get(p1, adj2, 0, 0, vis);
        p2 = {-1, INT_MIN};
        vis = vector<int>(m, 0);
        get(p2, adj2, p1.first, 0, vis);
        int d2 = p2.second;
        if(edges1.empty()) d1 = 0;
        if(edges2.empty()) d2 = 0;
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};

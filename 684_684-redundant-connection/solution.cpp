// Link: https://leetcode.com/problems/redundant-connection/description
// Description
// In this problem, a tree is an
// undirected graph
// that is connected and has no cycles.
// You are given a graph that started as a tree with
// n
// nodes labeled from
// 1
// to
// n
// , with one additional edge added. The added edge has two
// different
// vertices chosen from
// 1
// to
// n
// , and was not an edge that already existed. The graph is represented as an array
// edges
// of length
// n
// where
// edges[i] = [a
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
// in the graph.
// Return
// an edge that can be removed so that the resulting graph is a tree of
// n
// nodes
// . If there are multiple answers, return the answer that occurs last in the input.
// Example 1:
// Input:
// edges = [[1,2],[1,3],[2,3]]
// Output:
// [2,3]
// Example 2:
// Input:
// edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output:
// [1,4]
// Constraints:
// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= a
// i
// < b
// i
// <= edges.length
// a
// i
// != b
// i
// There are no repeated edges.
// The given graph is connected.

class Solution {
public:
    int find(int n, vector<int> &parent){
        int p = parent[n];
        while(p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool union_f(int n1, int n2, vector<int> &parent, vector<int> &rank){
        int par1 = find(n1, parent);
        int par2 = find(n2, parent);
        
        if(par1 == par2){
            return false;
        }
        if(rank[par1] < rank[par2]){
            parent[par1] = par2;
            rank[par2] += rank[par1];
        }
        else if(rank[par1] > rank[par2]){
            parent[par2] = par1;
            rank[par1] += rank[par2];
        }
        else{
            parent[par2] = par1;
            rank[par1] += rank[par2];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents, rank(n+1, 1);
        for(int i = 0; i < n+1; i++){
            parents.push_back(i);
        }
        for(auto & e : edges){
            int n1 = e[0];
            int n2 = e[1];
            if(!union_f(n1, n2, parents, rank)){
                return {n1,n2};
            }
        }
        return {};
    }
};

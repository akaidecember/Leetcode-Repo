// Link: https://leetcode.com/problems/graph-valid-tree/description
// Description
// You have a graph of
// n
// nodes labeled from
// 0
// to
// n - 1
// . You are given an integer n and a list of
// edges
// where
// edges[i] = [a
// i
// , b
// i
// ]
// indicates that there is an undirected edge between nodes
// a
// i
// and
// b
// i
// in the graph.
// Return
// true
// if the edges of the given graph make up a valid tree, and
// false
// otherwise
// .
// Example 1:
// Input:
// n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
// Output:
// true
// Example 2:
// Input:
// n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
// Output:
// false
// Constraints:
// 1 <= n <= 2000
// 0 <= edges.length <= 5000
// edges[i].length == 2
// 0 <= a
// i
// , b
// i
// < n
// a
// i
// != b
// i
// There are no self-loops or repeated edges.

class Solution {
private:
    vector<int> parent, rank;
    int count;

public:
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void Union(int x, int y){
        int a = find(x), b = find(y);

        if(a != b){
            if(rank[a] > rank[b]){
                parent[b] = a;
            }
            else if(rank[a] < rank[b]){
                parent[a] = b;
            }
            else{
                parent[b] = a;
                rank[a]++;
            }

            count--;
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() >= n){
            return false;
        }

        count = n;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n);

        for(auto& e : edges){
            Union(e[0], e[1]);
        }
        
        return count == 1 ? true : false;
    }
};

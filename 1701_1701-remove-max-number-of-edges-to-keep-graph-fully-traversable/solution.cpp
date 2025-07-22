// Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description
// Description
// Alice and Bob have an undirected graph of
// n
// nodes and three types of edges:
// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array
// edges
// where
// edges[i] = [type
// i
// , u
// i
// , v
// i
// ]
// represents a bidirectional edge of type
// type
// i
// between nodes
// u
// i
// and
// v
// i
// , find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.
// Return
// the maximum number of edges you can remove, or return
// -1
// if Alice and Bob cannot fully traverse the graph.
// Example 1:
// Input:
// n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output:
// 2
// Explanation:
// If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:
// Input:
// n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output:
// 0
// Explanation:
// Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:
// Input:
// n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output:
// -1
// Explanation:
// In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
// Constraints:
// 1 <= n <= 10
// 5
// 1 <= edges.length <= min(10
// 5
// , 3 * n * (n - 1) / 2)
// edges[i].length == 3
// 1 <= type
// i
// <= 3
// 1 <= u
// i
// < v
// i
// <= n
// All tuples
// (type
// i
// , u
// i
// , v
// i
// )
// are distinct.

class uf{
private:
    int n;
    vector<int> parent;
    vector<int> rank;

public:
    uf(int n){
        this->n = n;
        for(int i = 0; i < n+1; i++) this->parent.push_back(i);
        rank = vector<int>(n+1, 1);
    }

    int find(int x){
        while(x != parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    int union_f(int x1, int x2){
        int p1 = find(x1), p2 = find(x2);
        if(p1 == p2) return 0;
        if(rank[p1] > rank[p2]){
            rank[p1] += rank[p2];
            parent[p2] = p1;
        }
        else{
            rank[p2] += rank[p1];
            parent[p1] = p2;
        }
        n--;
        return 1;
    }

    bool isConnected(){
        return n <= 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        auto alice = uf(n);
        auto bob = uf(n);
        int count = 0;
        for(auto e : edges){    
            if(e[0] == 3){
                count += (alice.union_f(e[1], e[2]) | bob.union_f(e[1], e[2]));
            }
        }
        for(auto e : edges){
            if(e[0] == 1){
                count += alice.union_f(e[1], e[2]);
            }
            else if(e[0] == 2){
                count += bob.union_f(e[1], e[2]);
            }
        }
        if(bob.isConnected() && alice.isConnected()){
            return edges.size() - count;
        }
        return -1;
    }
};

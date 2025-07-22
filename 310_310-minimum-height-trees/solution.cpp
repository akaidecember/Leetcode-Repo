// Link: https://leetcode.com/problems/minimum-height-trees/description
// Description
// A tree is an undirected graph in which any two vertices are connected by
// exactly
// one path. In other words, any connected graph without simple cycles is a tree.
// Given a tree of
// n
// nodes labelled from
// 0
// to
// n - 1
// , and an array of
// n - 1
// edges
// where
// edges[i] = [a
// i
// , b
// i
// ]
// indicates that there is an undirected edge between the two nodes
// a
// i
// and
// b
// i
// in the tree, you can choose any node of the tree as the root. When you select a node
// x
// as the root, the result tree has height
// h
// . Among all possible rooted trees, those with minimum height (i.e.
// min(h)
// )  are called
// minimum height trees
// (MHTs).
// Return
// a list of all
// MHTs'
// root labels
// . You can return the answer in
// any order
// .
// The
// height
// of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
// Example 1:
// Input:
// n = 4, edges = [[1,0],[1,2],[1,3]]
// Output:
// [1]
// Explanation:
// As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
// Example 2:
// Input:
// n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// Output:
// [3,4]
// Constraints:
// 1 <= n <= 2 * 10
// 4
// edges.length == n - 1
// 0 <= a
// i
// , b
// i
// < n
// a
// i
// != b
// i
// All the pairs
// (a
// i
// , b
// i
// )
// are distinct.
// The given input is
// guaranteed
// to be a tree and there will be
// no repeated
// edges.

class Solution {
public:
    /*
    Initializing the degree vector and building the adjacency list (adj) 
    from the given edges takes O(E) time.
    
    The main part of the algorithm is the BFS loop, which iterates 
    until there are only one or two nodes left (n > 2). In each iteration of 
    this loop, we process each node once and each edge once. Therefore, the 
    total time complexity of this loop is proportional to the sum of the number 
    of nodes and the number of edges, which is O(V + E).

    O(V) time for iterating through at most all the nodes in the graph.

    So, time complexity: O(V+E)

    Space complexity would also be O(V+E) as adj would use that.
    Other structures are simply using O(V) space as they all are 
    atmost of size n.
    */

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Return empty if n <= 0 or 0 if 1 node present
        if(n <= 0) return {};
        // Return 0 if only one node present
        if(n == 1) return {0};

        vector<int> ret;
        vector<int> degree(n, 0);
        vector<unordered_set<int>> adj(n);
        queue<int> q;

        for(const auto& e : edges){
            // If a node is encountered more than once, it's 
            // degree will be > 1
            degree[e[0]]++;
            degree[e[1]]++;
            // Since the graph is un-directed, link the nodes
            // to each other
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        // Push all degree 1 nodes onto the queue
        for(int i = 0; i < n; ++i){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        // There will be atmost 2 nodes that can be
        // a root while maintaining MHT
        while(n > 2){
            int size = q.size();
            n -= size;
            // Since the queue only has degree one nodes, 
            // by removing the nodes, it decrements the degree of
            // it's neighbors. If that neighbor then becomes a 1 degree
            // node, then it is added to the queue to be removed later.
            while(size-- > 0){
                int temp = q.front();
                q.pop();
                for(const auto& v : adj[temp]){
                    degree[v]--;
                    if(degree[v] == 1){
                        q.push(v);
                    }
                }
            }
        }
        // This code will terminate if there are lesser than or equal to 2 nodes
        // remaining (that is the number of nodes with degree one all removed
        // except the center) 
        while(!q.empty()){
            // Simply return all the elements of the queue 
            // The only ones remaining would be the central nodes
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};

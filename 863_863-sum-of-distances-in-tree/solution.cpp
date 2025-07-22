// Link: https://leetcode.com/problems/sum-of-distances-in-tree/description
// Description
// There is an undirected connected tree with
// n
// nodes labeled from
// 0
// to
// n - 1
// and
// n - 1
// edges.
// You are given the integer
// n
// and the array
// edges
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
// in the tree.
// Return an array
// answer
// of length
// n
// where
// answer[i]
// is the sum of the distances between the
// i
// th
// node in the tree and all other nodes.
// Example 1:
// Input:
// n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output:
// [8,12,6,10,10,10]
// Explanation:
// The tree is shown above.
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.
// Hence, answer[0] = 8, and so on.
// Example 2:
// Input:
// n = 1, edges = []
// Output:
// [0]
// Example 3:
// Input:
// n = 2, edges = [[1,0]]
// Output:
// [1,1]
// Constraints:
// 1 <= n <= 3 * 10
// 4
// edges.length == n - 1
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
// The given input represents a valid tree.

class Solution {
public:
    void post_order(int root, int prev, vector<int> &ret, vector<unordered_set<int>> &edges, vector<int> &count){
        for(const auto& i : edges[root]){
            if(i == prev) continue;
            post_order(i, root, ret, edges, count);
            count[root] += count[i];
            ret[root] += ret[i] + count[i];
        }
        count[root]++;
    }

    void pre_order(int root, int prev, vector<int> &ret, vector<unordered_set<int>> &edges, vector<int> &count){
        for(const auto& i : edges[root]){
            if(i == prev) continue;
            ret[i] = ret[root] - count[i] + count.size() - count[i];
            pre_order(i, root, ret, edges, count);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ret(n, 0);
        vector<int> count(n, 0);
        vector<unordered_set<int>> adj(n);
        for(const auto& e : edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        post_order(0, -1, ret, adj, count);
        pre_order(0, -1, ret, adj, count);
        return ret;
    }
};

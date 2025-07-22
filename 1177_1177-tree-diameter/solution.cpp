// Link: https://leetcode.com/problems/tree-diameter/description
// Description
// The
// diameter
// of a tree is
// the number of edges
// in the longest path in that tree.
// There is an undirected tree of
// n
// nodes labeled from
// 0
// to
// n - 1
// . You are given a 2D array
// edges
// where
// edges.length == n - 1
// and
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
// in the tree.
// Return
// the
// diameter
// of the tree
// .
// Example 1:
// Input:
// edges = [[0,1],[0,2]]
// Output:
// 2
// Explanation:
// The longest path of the tree is the path 1 - 0 - 2.
// Example 2:
// Input:
// edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
// Output:
// 4
// Explanation:
// The longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
// Constraints:
// n == edges.length + 1
// 1 <= n <= 10
// 4
// 0 <= a
// i
// , b
// i
// < n
// a
// i
// != b
// i

class Solution {
public:
    int dfs(int node, vector<vector<int>> &graph, int &ret){
        int first = 0, second = 0;

        for(const auto& nei : graph[node]){
            int count = dfs(nei, graph, ret);

            if(count > first){
                second = first;
                first = count;
            }
            else if(count > second){
                second = count;
            }
        }

        ret = max(ret, first + second);

        return first + 1;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size(), ret = 0;

        if(n == 0){
            return 0;
        }

        vector<vector<int>> graph(n + 1);

        for(const auto& e : edges){
            graph[e[0]].push_back(e[1]);
        }

        dfs(0, graph, ret);
        dfs(1, graph, ret);

        return ret;
    }
};

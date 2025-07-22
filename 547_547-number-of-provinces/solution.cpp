// Link: https://leetcode.com/problems/number-of-provinces/description
// Description
// There are
// n
// cities. Some of them are connected, while some are not. If city
// a
// is connected directly with city
// b
// , and city
// b
// is connected directly with city
// c
// , then city
// a
// is connected indirectly with city
// c
// .
// A
// province
// is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an
// n x n
// matrix
// isConnected
// where
// isConnected[i][j] = 1
// if the
// i
// th
// city and the
// j
// th
// city are directly connected, and
// isConnected[i][j] = 0
// otherwise.
// Return
// the total number of
// provinces
// .
// Example 1:
// Input:
// isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output:
// 2
// Example 2:
// Input:
// isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output:
// 3
// Constraints:
// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j]
// is
// 1
// or
// 0
// .
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0, i = 0;
        vector<bool> visited(isConnected.size(), false);
        for(auto v : visited){
            if(!v){
                dfs(visited, i, isConnected);
                count++;
            }
            i++;
        }
        return count;
    }

    void dfs(vector<bool> &visited, int i, vector<vector<int>> &graph){
        visited[i] = true;
        for(int j = 0; j < graph[i].size(); j++){
            if(graph[i][j] == 1 && !visited[j]){
                dfs(visited, j, graph);
            }
        }
    }
};

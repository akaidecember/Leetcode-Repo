// Link: https://leetcode.com/problems/map-of-highest-peak/description
// Description
// You are given an integer matrix
// isWater
// of size
// m x n
// that represents a map of
// land
// and
// water
// cells.
// If
// isWater[i][j] == 0
// , cell
// (i, j)
// is a
// land
// cell.
// If
// isWater[i][j] == 1
// , cell
// (i, j)
// is a
// water
// cell.
// You must assign each cell a height in a way that follows these rules:
// The height of each cell must be non-negative.
// If the cell is a
// water
// cell, its height must be
// 0
// .
// Any two adjacent cells must have an absolute height difference of
// at most
// 1
// . A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// Find an assignment of heights such that the maximum height in the matrix is
// maximized
// .
// Return
// an integer matrix
// height
// of size
// m x n
// where
// height[i][j]
// is cell
// (i, j)
// 's height. If there are multiple solutions, return
// any
// of them
// .
// Example 1:
// Input:
// isWater = [[0,1],[0,0]]
// Output:
// [[1,0],[2,1]]
// Explanation:
// The image shows the assigned heights of each cell.
// The blue cell is the water cell, and the green cells are the land cells.
// Example 2:
// Input:
// isWater = [[0,0,1],[1,0,0],[0,0,0]]
// Output:
// [[1,1,0],[0,1,1],[1,2,2]]
// Explanation:
// A height of 2 is the maximum possible height of any assignment.
// Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
// Constraints:
// m == isWater.length
// n == isWater[i].length
// 1 <= m, n <= 1000
// isWater[i][j]
// is
// 0
// or
// 1
// .
// There is at least
// one
// water cell.
// Note:
// This question is the same as 542:
// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n, -1));
        queue<int> q;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    ret[i][j] = 0, q.push(i * n + j);
                }
            }
        }

        while (!q.empty()) {
            int x = q.front() / n, y = q.front() % n; 
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && ret[nx][ny] == -1){
                    ret[nx][ny] = ret[x][y] + 1, q.push(nx * n + ny);
                }
            }
        }
        return ret;
    }
};

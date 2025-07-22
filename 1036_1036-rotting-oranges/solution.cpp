// Link: https://leetcode.com/problems/rotting-oranges/description
// Description
// You are given an
// m x n
// grid
// where each cell can have one of three values:
// 0
// representing an empty cell,
// 1
// representing a fresh orange, or
// 2
// representing a rotten orange.
// Every minute, any fresh orange that is
// 4-directionally adjacent
// to a rotten orange becomes rotten.
// Return
// the minimum number of minutes that must elapse until no cell has a fresh orange
// . If
// this is impossible, return
// -1
// .
// Example 1:
// Input:
// grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output:
// 4
// Example 2:
// Input:
// grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output:
// -1
// Explanation:
// The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:
// Input:
// grid = [[0,2]]
// Output:
// 0
// Explanation:
// Since there are already no fresh oranges at minute 0, the answer is just 0.
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j]
// is
// 0
// ,
// 1
// , or
// 2
// .

class Solution {
private:
    array<array<int, 2>, 4> dirs = {{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}};
    
    void bfs(int &q_n, int &fresh_count, queue<pair<int, int>> &rotten_q, vector<vector<int>>& grid){
        if(q_n <= 0){
            return;
        }
        auto [x, y] = rotten_q.front();
        rotten_q.pop();

        int m = grid.size(), n = grid[0].size();

        for(const auto& d : dirs){
            int row = x + d[0], col = y + d[1];

            if(row < m and row >= 0 and col < n and col >= 0 and grid[row][col] == 1){
                grid[row][col] = 2;
                fresh_count--;
                rotten_q.push({row, col});
            }
        }
        bfs(--q_n, fresh_count, rotten_q, grid);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten_q;
        int fresh_count = 0, m = grid.size(), n = grid[0].size(), ret = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0;j < n; j++){
                if(grid[i][j] == 2){
                    rotten_q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh_count++;
                }
            }
        }

        if(fresh_count == 0){
            return 0;
        }        

        while(!rotten_q.empty()){
            int temp_n = rotten_q.size();
            bfs(temp_n, fresh_count, rotten_q, grid);
            ret++;
        }

        return (fresh_count == 0) ? ret - 1 : -1;
    }
};

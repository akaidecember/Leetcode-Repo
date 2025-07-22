// Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description
// Description
// You are given two integers
// m
// and
// n
// representing a
// 0-indexed
// m x n
// grid. You are also given two 2D integer arrays
// guards
// and
// walls
// where
// guards[i] = [row
// i
// , col
// i
// ]
// and
// walls[j] = [row
// j
// , col
// j
// ]
// represent the positions of the
// i
// th
// guard and
// j
// th
// wall respectively.
// A guard can see
// every
// cell in the four cardinal directions (north, east, south, or west) starting from their position unless
// obstructed
// by a wall or another guard. A cell is
// guarded
// if there is
// at least
// one guard that can see it.
// Return
// the number of unoccupied cells that are
// not
// guarded
// .
// Example 1:
// Input:
// m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
// Output:
// 7
// Explanation:
// The guarded and unguarded cells are shown in red and green respectively in the above diagram.
// There are a total of 7 unguarded cells, so we return 7.
// Example 2:
// Input:
// m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
// Output:
// 4
// Explanation:
// The unguarded cells are shown in green in the above diagram.
// There are a total of 4 unguarded cells, so we return 4.
// Constraints:
// 1 <= m, n <= 10
// 5
// 2 <= m * n <= 10
// 5
// 1 <= guards.length, walls.length <= 5 * 10
// 4
// 2 <= guards.length + walls.length <= m * n
// guards[i].length == walls[j].length == 2
// 0 <= row
// i
// , row
// j
// < m
// 0 <= col
// i
// , col
// j
// < n
// All the positions in
// guards
// and
// walls
// are
// unique
// .

class Solution {
private:
    vector<vector<int>> grid;
    int ret;

public:
    void dfs(int x, int y, int dx, int dy){
        int x1 = x + dx, y1 = y + dy, m = grid.size(), n = grid[0].size();

        while(x1 >= 0 and x1 < m and y1 >= 0 and y1 < n){
            if(grid[x1][y1] >= 1){
                break;
            }
            if(grid[x1][y1] == 0){
                grid[x1][y1] = -1;
                ret--;
            }
            x1 += dx;
            y1 += dy;
        }
    }


    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ret = (m * n) - guards.size() - walls.size();
        grid.resize(m, vector<int>(n, 0));

        for(const auto& g : guards){
            grid[g[0]][g[1]] = 1;
        }

        for(const auto& w : walls){
            grid[w[0]][w[1]] = 2;
        }

        for(const auto& g : guards){
            dfs(g[0], g[1], 0, -1);
            dfs(g[0], g[1], 0, 1);
            dfs(g[0], g[1], -1, 0);
            dfs(g[0], g[1], 1, 0);
        }

        return ret;
    }
};

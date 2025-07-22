// Link: https://leetcode.com/problems/number-of-distinct-islands/description
// Description
// You are given an
// m x n
// binary matrix
// grid
// . An island is a group of
// 1
// 's (representing land) connected
// 4-directionally
// (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
// An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
// Return
// the number of
// distinct
// islands
// .
// Example 1:
// Input:
// grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
// Output:
// 1
// Example 2:
// Input:
// grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
// Output:
// 3
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j]
// is either
// 0
// or
// 1
// .

class Solution {
private:
    vector<vector<int>> dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void bfs(vector<vector<int>> & grid, int i, int j, int base_i, int base_j, vector<pair<int,int>> &shape){
        int m = grid.size(), n = grid[0].size(); 
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        shape.push_back({i - base_i, j - base_j});
        for(const auto& d : dirs){
            int vir = d[0];
            int hor = d[1];
            bfs(grid, i + vir, j + hor,base_i, base_j, shape);
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int,int>>> st;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    vector<pair<int,int>> shape;
                    bfs(grid, i, j, i, j, shape);
                    st.insert(shape);
                }
            }
        }
        return st.size();
    }
};

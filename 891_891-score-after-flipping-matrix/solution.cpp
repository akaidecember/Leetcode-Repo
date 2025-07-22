// Link: https://leetcode.com/problems/score-after-flipping-matrix/description
// Description
// You are given an
// m x n
// binary matrix
// grid
// .
// A
// move
// consists of choosing any row or column and toggling each value in that row or column (i.e., changing all
// 0
// 's to
// 1
// 's, and all
// 1
// 's to
// 0
// 's).
// Every row of the matrix is interpreted as a binary number, and the
// score
// of the matrix is the sum of these numbers.
// Return
// the highest possible
// score
// after making any number of
// moves
// (including zero moves)
// .
// Example 1:
// Input:
// grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output:
// 39
// Explanation:
// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
// Example 2:
// Input:
// grid = [[0]]
// Output:
// 1
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 20
// grid[i][j]
// is either
// 0
// or
// 1
// .

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = 0;
        // If the first number of the row is 0, flip the row.
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < n; j++){
                    grid[i][j] = (grid[i][j] == 0) ? 1 : 0;
                }
            }
        }
        // If the count of 0 in col greater than count of 1, flip col
        for(int i = 0; i < n; i++){
            int count_one = 0;
            for(int j = 0; j < m; j++){
                count_one += grid[j][i];
            }
            if(count_one < m - count_one){
                for(int k = 0; k < m; k++){
                    grid[k][i] = (grid[k][i] == 0) ? 1 : 0;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ret += grid[i][j] << (n - j - 1);
            }
        }
        return ret;
    }
};

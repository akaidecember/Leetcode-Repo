// Link: https://leetcode.com/problems/count-sub-islands/description
// Description
// You are given two
// m x n
// binary matrices
// grid1
// and
// grid2
// containing only
// 0
// 's (representing water) and
// 1
// 's (representing land). An
// island
// is a group of
// 1
// 's connected
// 4-directionally
// (horizontal or vertical). Any cells outside of the grid are considered water cells.
// An island in
// grid2
// is considered a
// sub-island
// if there is an island in
// grid1
// that contains
// all
// the cells that make up
// this
// island in
// grid2
// .
// Return the
// number
// of islands in
// grid2
// that are considered
// sub-islands
// .
// Example 1:
// Input:
// grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// Output:
// 3
// Explanation:
// In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
// Example 2:
// Input:
// grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
// Output:
// 2
// Explanation:
// In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
// Constraints:
// m == grid1.length == grid2.length
// n == grid1[i].length == grid2[i].length
// 1 <= m, n <= 500
// grid1[i][j]
// and
// grid2[i][j]
// are either
// 0
// or
// 1
// .

class Solution {
public:
    int r, c;
    const int d[5]={0,1,0,-1,0};
    inline bool outside(int i, int j){
        return i<0 ||i>=r||j<0 || j>=c;
    }
    bool dfs(int i, int j, int mark, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if (grid1[i][j] != 1) return 0;

        grid2[i][j] = mark; 
        bool isSub=1;
        for (int a=0; a < 4; a++) {
            int s =i+d[a], t=j+d[a+1];
            if (outside(s, t) || grid2[s][t] != 1) continue;
            if (grid1[s][t]!=1) isSub=0;
            if (!dfs(s, t, mark, grid1, grid2)) 
                isSub=0;
        }
        return isSub;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        r=grid1.size(), c=grid1[0].size();
        int cnt=0, mark=2;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if (grid2[i][j]==1)
                    cnt+=dfs(i, j, mark++, grid1, grid2);
            }
        }
        return cnt;
    }
};

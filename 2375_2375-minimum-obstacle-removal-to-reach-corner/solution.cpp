// Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description
// Description
// You are given a
// 0-indexed
// 2D integer array
// grid
// of size
// m x n
// . Each cell has one of two values:
// 0
// represents an
// empty
// cell,
// 1
// represents an
// obstacle
// that may be removed.
// You can move up, down, left, or right from and to an empty cell.
// Return
// the
// minimum
// number of
// obstacles
// to
// remove
// so you can move from the upper left corner
// (0, 0)
// to the lower right corner
// (m - 1, n - 1)
// .
// Example 1:
// Input:
// grid = [[0,1,1],[1,1,0],[1,1,0]]
// Output:
// 2
// Explanation:
// We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
// It can be shown that we need to remove at least 2 obstacles, so we return 2.
// Note that there may be other ways to remove 2 obstacles to create a path.
// Example 2:
// Input:
// grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
// Output:
// 0
// Explanation:
// We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// 5
// 2 <= m * n <= 10
// 5
// grid[i][j]
// is either
// 0
// or
// 1
// .
// grid[0][0] == grid[m - 1][n - 1] == 0

using int2 = pair<int, int>; // (dist, idx(i,j))
const static int d[5] = {0, 1, 0, -1, 0};
class Solution {
public:
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }
    inline static int idx(int i, int j, int m){
        return i*m+j;
    }

    static int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unsigned dist[100000];
        fill(dist, dist+n*m, INT_MAX);
        priority_queue<int2, vector<int2>, greater<int2>> pq;

        pq.emplace(0, 0);
        dist[0] = 0;

        while (!pq.empty()) {
            auto [currD, ij] = pq.top();
            auto [i, j]=div(ij, m);
            pq.pop();

            // reach the target
            if (i == n - 1 && j == m - 1)
                return currD;

            // Traverse all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m))
                    continue;

                // minimum distance to reach (r, s)
                int nextD = grid[r][s] + currD;

                int rs=idx(r, s, m);
                // update if this path having shorter distance
                if (nextD < dist[rs]) {
                    dist[rs] = nextD;
                    pq.emplace(nextD, rs);
                }
            }
        }
        return -1; // never reach
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

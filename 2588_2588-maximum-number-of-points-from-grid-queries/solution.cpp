// Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description
// Description
// You are given an
// m x n
// integer matrix
// grid
// and an array
// queries
// of size
// k
// .
// Find an array
// answer
// of size
// k
// such that for each integer
// queries[i]
// you start in the
// top left
// cell of the matrix and repeat the following process:
// If
// queries[i]
// is
// strictly
// greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any
// adjacent
// cell in all
// 4
// directions: up, down, left, and right.
// Otherwise, you do not get any points, and you end this process.
// After the process,
// answer[i]
// is the
// maximum
// number of points you can get.
// Note
// that for each query you are allowed to visit the same cell
// multiple
// times.
// Return
// the resulting array
// answer
// .
// Example 1:
// Input:
// grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
// Output:
// [5,8,1]
// Explanation:
// The diagrams above show which cells we visit to get points for each query.
// Example 2:
// Input:
// grid = [[5,2,1],[1,1,2]], queries = [3]
// Output:
// [0]
// Explanation:
// We can not get any points because the value of the top left cell is already greater than or equal to 3.
// Constraints:
// m == grid.length
// n == grid[i].length
// 2 <= m, n <= 1000
// 4 <= m * n <= 10
// 5
// k == queries.length
// 1 <= k <= 10
// 4
// 1 <= grid[i][j], queries[i] <= 10
// 6

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.emplace_back(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size(), 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        minHeap.emplace(grid[0][0], make_pair(0, 0));
        visited[0][0] = true;
        int points = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto& [queryVal, queryIdx] : sortedQueries) {
            while (!minHeap.empty() && minHeap.top().first < queryVal) {
                auto [val, pos] = minHeap.top();
                minHeap.pop();
                int row = pos.first, col = pos.second;
                points++;

                for (auto& [dr, dc] : directions) {
                    int nr = row + dr, nc = col + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                        minHeap.emplace(grid[nr][nc], make_pair(nr, nc));
                        visited[nr][nc] = true;
                    }
                }
            }
            result[queryIdx] = points;
        }

        return result;
    }
};

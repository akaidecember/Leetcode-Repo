// Link: https://leetcode.com/problems/equal-row-and-column-pairs/description
// Description
// Given a
// 0-indexed
// n x n
// integer matrix
// grid
// ,
// return the number of pairs
// (r
// i
// , c
// j
// )
// such that row
// r
// i
// and column
// c
// j
// are equal
// .
// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).
// Example 1:
// Input:
// grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output:
// 1
// Explanation:
// There is 1 equal row and column pair:
// - (Row 2, Column 1): [2,7,7]
// Example 2:
// Input:
// grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// Output:
// 3
// Explanation:
// There are 3 equal row and column pairs:
// - (Row 0, Column 0): [3,1,2,2]
// - (Row 2, Column 2): [2,4,2,2]
// - (Row 3, Column 2): [2,4,2,2]
// Constraints:
// n == grid.length == grid[i].length
// 1 <= n <= 200
// 1 <= grid[i][j] <= 10
// 5

class Solution {
    public int equalPairs(int[][] grid) {
        Map<List<Integer>, Integer> mp = new HashMap<>();
        int ret = 0;

        for (int[] row : grid) {
            List<Integer> rowList = new ArrayList<>();
            for (int element : row) {
                rowList.add(element);
            }
            mp.put(rowList, mp.getOrDefault(rowList, 0) + 1);
        }

        for (int col = 0; col < grid[0].length; col++) {
            List<Integer> columnList = new ArrayList<>();
            for (int row = 0; row < grid.length; row++) {
                columnList.add(grid[row][col]);
            }
            ret += mp.getOrDefault(columnList, 0);
        }

        return ret;
    }
}
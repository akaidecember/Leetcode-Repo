// Link: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description
// Description
// You are given two arrays
// rowSum
// and
// colSum
// of non-negative integers where
// rowSum[i]
// is the sum of the elements in the
// i
// th
// row and
// colSum[j]
// is the sum of the elements of the
// j
// th
// column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.
// Find any matrix of
// non-negative
// integers of size
// rowSum.length x colSum.length
// that satisfies the
// rowSum
// and
// colSum
// requirements.
// Return
// a 2D array representing
// any
// matrix that fulfills the requirements
// . It's guaranteed that
// at least one
// matrix that fulfills the requirements exists.
// Example 1:
// Input:
// rowSum = [3,8], colSum = [4,7]
// Output:
// [[3,0],
//          [1,7]]
// Explanation:
// 0
// th
// row: 3 + 0 = 3 == rowSum[0]
// 1
// st
// row: 1 + 7 = 8 == rowSum[1]
// 0
// th
// column: 3 + 1 = 4 == colSum[0]
// 1
// st
// column: 0 + 7 = 7 == colSum[1]
// The row and column sums match, and all matrix elements are non-negative.
// Another possible matrix is: [[1,2],
//                              [3,5]]
// Example 2:
// Input:
// rowSum = [5,7,10], colSum = [8,6,8]
// Output:
// [[0,5,0],
//          [6,1,0],
//          [2,0,8]]
// Constraints:
// 1 <= rowSum.length, colSum.length <= 500
// 0 <= rowSum[i], colSum[i] <= 10
// 8
// sum(rowSum) == sum(colSum)

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size(), col = colSum.size();
        // i for row, j for col
        int i = 0, j = 0;
        vector<vector<int>> ret(row, vector<int>(col, 0));

        while(i < row || j < col){
            if(i >= row){
                ret[row - 1][j] = colSum[j];
                j++;
                continue;
            }
            else if(j >= col){
                ret[i][col - 1] = rowSum[i];
                i++;
                continue;
            }
            int val = min(rowSum[i], colSum[j]);
            rowSum[i] -= val;
            colSum[j] -= val;
            ret[i][j] = val;

            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
        }

        return ret;
    }
};

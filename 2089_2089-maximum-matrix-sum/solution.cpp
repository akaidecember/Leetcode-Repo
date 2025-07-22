// Link: https://leetcode.com/problems/maximum-matrix-sum/description
// Description
// You are given an
// n x n
// integer
// matrix
// . You can do the following operation
// any
// number of times:
// Choose any two
// adjacent
// elements of
// matrix
// and
// multiply
// each of them by
// -1
// .
// Two elements are considered
// adjacent
// if and only if they share a
// border
// .
// Your goal is to
// maximize
// the summation of the matrix's elements. Return
// the
// maximum
// sum of the matrix's elements using the operation mentioned above.
// Example 1:
// Input:
// matrix = [[1,-1],[-1,1]]
// Output:
// 4
// Explanation:
// We can follow the following steps to reach sum equals 4:
// - Multiply the 2 elements in the first row by -1.
// - Multiply the 2 elements in the first column by -1.
// Example 2:
// Input:
// matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
// Output:
// 16
// Explanation:
// We can follow the following step to reach sum equals 16:
// - Multiply the 2 last elements in the second row by -1.
// Constraints:
// n == matrix.length == matrix[i].length
// 2 <= n <= 250
// -10
// 5
// <= matrix[i][j] <= 10
// 5

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0LL;
        int min_val = INT_MAX;
        int ct_ng = 0;

        for (const auto& row : matrix) {
            for (int x : row) {
                sum += abs(x); 
                min_val = min(min_val, abs(x)); 
                if (x < 0) {
                    ct_ng++; 
                }
            }
        }

        if (ct_ng % 2 != 0) {
            sum -= 2 * min_val;
        }

        return sum;
    }
};


// Link: https://leetcode.com/problems/student-attendance-record-ii/description
// Description
// An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
// 'A'
// : Absent.
// 'L'
// : Late.
// 'P'
// : Present.
// Any student is eligible for an attendance award if they meet
// both
// of the following criteria:
// The student was absent (
// 'A'
// ) for
// strictly
// fewer than 2 days
// total
// .
// The student was
// never
// late (
// 'L'
// ) for 3 or more
// consecutive
// days.
// Given an integer
// n
// , return
// the
// number
// of possible attendance records of length
// n
// that make a student eligible for an attendance award. The answer may be very large, so return it
// modulo
// 10
// 9
// + 7
// .
// Example 1:
// Input:
// n = 2
// Output:
// 8
// Explanation:
// There are 8 records with length 2 that are eligible for an award:
// "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
// Example 2:
// Input:
// n = 1
// Output:
// 3
// Example 3:
// Input:
// n = 10101
// Output:
// 183236316
// Constraints:
// 1 <= n <= 10
// 5

class Solution {
public:
    const int MOD = 1000000007;
    vector<vector<vector<long long>>> dp;

    long long solver(int i, int a, int l){
        if(a >= 2 || l >= 3){
            return 0;
        }
        if(i == 0){
            return 1;
        }
        if(dp[i][a][l] != -1){
            return dp[i][a][l];
        }
        long long ret = solver(i-1, a, 0);
        ret = ret + solver(i-1, a+1, 0);
        ret = ret + solver(i-1, a, l+1);
        dp[i][a][l] = ret % MOD;
        return dp[i][a][l];
    }

    int checkRecord(int n) {
        // memset(dp, -1, sizeof(dp));
        dp.assign(n+1, vector<vector<long long>>(2, vector<long long>(3, -1)));
        return solver(n, 0, 0) % MOD;
    }
};

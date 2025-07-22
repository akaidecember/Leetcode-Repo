// Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description
// Description
// A sequence
// x
// 1
// , x
// 2
// , ..., x
// n
// is
// Fibonacci-like
// if:
// n >= 3
// x
// i
// + x
// i+1
// == x
// i+2
// for all
// i + 2 <= n
// Given a
// strictly increasing
// array
// arr
// of positive integers forming a sequence, return
// the
// length
// of the longest Fibonacci-like subsequence of
// arr
// . If one does not exist, return
// 0
// .
// A
// subsequence
// is derived from another sequence
// arr
// by deleting any number of elements (including none) from
// arr
// , without changing the order of the remaining elements. For example,
// [3, 5, 8]
// is a subsequence of
// [3, 4, 5, 6, 7, 8]
// .
// Example 1:
// Input:
// arr = [1,2,3,4,5,6,7,8]
// Output:
// 5
// Explanation:
// The longest subsequence that is fibonacci-like: [1,2,3,5,8].
// Example 2:
// Input:
// arr = [1,3,7,11,12,14,18]
// Output:
// 3
// Explanation
// :
// The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
// Constraints:
// 3 <= arr.length <= 1000
// 1 <= arr[i] < arr[i + 1] <= 10
// 9

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr){
        int n = arr.size(), ret = 0;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        unordered_map<int, int> idx;

        for (int i = 0; i < n; i++) {
            idx[arr[i]] = i;
        }
        
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                int next = arr[i] + arr[j];
                if (idx.find(next) == idx.end()){
                    continue;
                }
                int k = idx[next];
                dp[j][k] = max(dp[j][k], 1 + dp[i][j]);
                ret = max(ret, dp[j][k]);
            }
        }
        return ret >= 3 ? ret : 0;
    }
};

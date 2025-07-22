// Link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description
// Description
// Given an integer array
// nums
// and an integer
// k
// , find three non-overlapping subarrays of length
// k
// with maximum sum and return them.
// Return the result as a list of indices representing the starting position of each interval (
// 0-indexed
// ). If there are multiple answers, return the lexicographically smallest one.
// Example 1:
// Input:
// nums = [1,2,1,2,6,7,5,1], k = 2
// Output:
// [0,3,5]
// Explanation:
// Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
// We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
// Example 2:
// Input:
// nums = [1,2,1,2,1,2,1,2,1], k = 2
// Output:
// [0,2,4]
// Constraints:
// 1 <= nums.length <= 2 * 10
// 4
// 1 <= nums[i] < 2
// 16
// 1 <= k <= floor(nums.length / 3)

class Solution {
public:
    int dp(vector<int>& sums, int k, int idx, int rem, vector<vector<int>>& memo) {
        if (rem == 0){
            return 0;
        }
        if (idx >= sums.size()){
            return rem > 0 ? INT_MIN : 0;
        }

        if (memo[idx][rem] != -1) {
            return memo[idx][rem];
        }

        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        memo[idx][rem] = max(withCurrent, skipCurrent);
        return memo[idx][rem];
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size() - k + 1;
        vector<int> sums(n);
        vector<vector<int>> memo(n, vector<int>(4, -1));
        vector<int> indices;
        int windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        sums[0] = windowSum;
        for (int i = k; i < nums.size(); i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            sums[i - k + 1] = windowSum;
        }

        dp(sums, k, 0, 3, memo);
        dfs(sums, k, 0, 3, memo, indices);
        return indices;
    }

    void dfs(vector<int>& sums, int k, int idx, int rem, vector<vector<int>>& memo, vector<int>& indices) {
        if (rem == 0){
            return;
        }
        if (idx >= sums.size()){
            return;
        }

        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        if (withCurrent >= skipCurrent) { 
            indices.push_back(idx);
            dfs(sums, k, idx + k, rem - 1, memo, indices);
        } 
        else {  
            dfs(sums, k, idx + 1, rem, memo, indices);
        }
    }
};

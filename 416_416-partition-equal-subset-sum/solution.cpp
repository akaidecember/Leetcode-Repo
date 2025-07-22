// Link: https://leetcode.com/problems/partition-equal-subset-sum/description
// Description
// Given an integer array
// nums
// , return
// true
// if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or
// false
// otherwise
// .
// Example 1:
// Input:
// nums = [1,5,11,5]
// Output:
// true
// Explanation:
// The array can be partitioned as [1, 5, 5] and [11].
// Example 2:
// Input:
// nums = [1,2,3,5]
// Output:
// false
// Explanation:
// The array cannot be partitioned into equal sum subsets.
// Constraints:
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

class Solution {
public:
    int helper(int idx, int target, const vector<int> &nums, vector<vector<int>> &dp){
        if(idx >= nums.size() or target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        dp[idx][target] = helper(idx + 1, target, nums, dp) or helper(idx + 1, target - nums[idx], nums, dp);
        return dp[idx][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        if(sum % 2 != 0){
            return false;
        }
        return helper(0, sum / 2, nums, dp);
    }
};

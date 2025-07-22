// Link: https://leetcode.com/problems/target-sum/description
// Description
// You are given an integer array
// nums
// and an integer
// target
// .
// You want to build an
// expression
// out of nums by adding one of the symbols
// '+'
// and
// '-'
// before each integer in nums and then concatenate all the integers.
// For example, if
// nums = [2, 1]
// , you can add a
// '+'
// before
// 2
// and a
// '-'
// before
// 1
// and concatenate them to build the expression
// "+2-1"
// .
// Return the number of different
// expressions
// that you can build, which evaluates to
// target
// .
// Example 1:
// Input:
// nums = [1,1,1,1,1], target = 3
// Output:
// 5
// Explanation:
// There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:
// Input:
// nums = [1], target = 1
// Output:
// 1
// Constraints:
// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int diff=sum-target;

        if (diff<0|| diff%2!=0) return 0;

        diff/=2;
        int dp[21][2001]={{0}};
        dp[0][0] = 1;

        for (int j=1; j <= n; j++) {
            for (int sum=0; sum <= diff; sum++) {
                dp[j][sum] = dp[j-1][sum]; 

                if (sum >= nums[j-1]) 
                    dp[j][sum]+=dp[j-1][sum-nums[j-1]];
            }
        }
        return dp[n][diff];
    }
};

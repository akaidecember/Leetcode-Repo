// Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description
// Description
// You are given an integer array
// nums
// . The
// absolute sum
// of a subarray
// [nums
// l
// , nums
// l+1
// , ..., nums
// r-1
// , nums
// r
// ]
// is
// abs(nums
// l
// + nums
// l+1
// + ... + nums
// r-1
// + nums
// r
// )
// .
// Return
// the
// maximum
// absolute sum of any
// (possibly empty)
// subarray of
// nums
// .
// Note that
// abs(x)
// is defined as follows:
// If
// x
// is a negative integer, then
// abs(x) = -x
// .
// If
// x
// is a non-negative integer, then
// abs(x) = x
// .
// Example 1:
// Input:
// nums = [1,-3,2,3,-4]
// Output:
// 5
// Explanation:
// The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
// Example 2:
// Input:
// nums = [2,-5,1,-4,3,-2]
// Output:
// 8
// Explanation:
// The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
// Constraints:
// 1 <= nums.length <= 10
// 5
// -10
// 4
// <= nums[i] <= 10
// 4

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int maxSum = INT_MIN;
       int sum = 0;

       for (int i: nums){
        sum += i;

        maxSum = max(sum, maxSum);

        if (sum < 0){
            sum = 0;
        }
       }
       int minSum = INT_MIN;
       int s = 0;
        for (int i: nums){
        s += i;

        minSum = max(abs(s), minSum);

        if (s > 0){
            s = 0;
        }
       } 
       return max(maxSum, minSum);
    }
};

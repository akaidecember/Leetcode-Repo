// Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description
// Description
// You are given an integer array
// nums
// and an integer
// k
// . Find the maximum subarray sum of all the subarrays of
// nums
// that meet the following conditions:
// The length of the subarray is
// k
// , and
// All the elements of the subarray are
// distinct
// .
// Return
// the maximum subarray sum of all the subarrays that meet the conditions
// .
// If no subarray meets the conditions, return
// 0
// .
// A
// subarray
// is a contiguous non-empty sequence of elements within an array.
// Example 1:
// Input:
// nums = [1,5,4,2,9,9,9], k = 3
// Output:
// 15
// Explanation:
// The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
// Example 2:
// Input:
// nums = [4,4,4], k = 3
// Output:
// 0
// Explanation:
// The subarrays of nums with length 3 are:
// - [4,4,4] which does not meet the requirements because the element 4 is repeated.
// We return 0 because no subarrays meet the conditions.
// Constraints:
// 1 <= k <= nums.length <= 10
// 5
// 1 <= nums[i] <= 10
// 5

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long k_sum = accumulate(nums.begin(), nums.begin() + k, 0LL), ret = 0;

        unordered_map<int, int> mp;

        for(int i = 0; i < k; i++){
            mp[nums[i]]++;
        }

        if(mp.size() == k){
            ret = k_sum;
        }

        for(int i = k; i < n; i++){
            k_sum -= static_cast<long long>(nums[i - k]);
            mp[nums[i - k]]--;

            if(mp[nums[i - k]] == 0){
                mp.erase(nums[i-k]);
            }

            k_sum += static_cast<long long>(nums[i]);
            mp[nums[i]]++;

            if(mp.size() == k){
                ret = max(ret, k_sum);
            }
        }

        return ret;
    }
};

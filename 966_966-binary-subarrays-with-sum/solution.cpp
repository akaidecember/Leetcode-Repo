// Link: https://leetcode.com/problems/binary-subarrays-with-sum/description
// Description
// Given a binary array
// nums
// and an integer
// goal
// , return
// the number of non-empty
// subarrays
// with a sum
// goal
// .
// A
// subarray
// is a contiguous part of the array.
// Example 1:
// Input:
// nums = [1,0,1,0,1], goal = 2
// Output:
// 4
// Explanation:
// The 4 subarrays are bolded and underlined below:
// [
// 1,0,1
// ,0,1]
// [
// 1,0,1,0
// ,1]
// [1,
// 0,1,0,1
// ]
// [1,0,
// 1,0,1
// ]
// Example 2:
// Input:
// nums = [0,0,0,0,0], goal = 0
// Output:
// 15
// Constraints:
// 1 <= nums.length <= 3 * 10
// 4
// nums[i]
// is either
// 0
// or
// 1
// .
// 0 <= goal <= nums.length

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int diff = sum - goal;
            if(mp.find(diff) != mp.end()){
                cnt += mp[diff];
            }
            if(mp.find(sum) != mp.end()){
                mp[sum]++;
            }
            else{
                mp[sum] = 1;
            }
        }
        return cnt;
    }
};

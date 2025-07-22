// Link: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description
// Description
// You are given an array
// nums
// of
// non-negative
// integers and an integer
// k
// .
// An array is called
// special
// if the bitwise
// OR
// of all of its elements is
// at least
// k
// .
// Return
// the length of the
// shortest
// special
// non-empty
// subarray
// of
// nums
// ,
// or return
// -1
// if no special subarray exists
// .
// Example 1:
// Input:
// nums = [1,2,3], k = 2
// Output:
// 1
// Explanation:
// The subarray
// [3]
// has
// OR
// value of
// 3
// . Hence, we return
// 1
// .
// Example 2:
// Input:
// nums = [2,1,8], k = 10
// Output:
// 3
// Explanation:
// The subarray
// [2,1,8]
// has
// OR
// value of
// 11
// . Hence, we return
// 3
// .
// Example 3:
// Input:
// nums = [1,2], k = 0
// Output:
// 1
// Explanation:
// The subarray
// [1]
// has
// OR
// value of
// 1
// . Hence, we return
// 1
// .
// Constraints:
// 1 <= nums.length <= 2 * 10
// 5
// 0 <= nums[i] <= 10
// 9
// 0 <= k <= 10
// 9

class Solution {
public:
int minimumSubarrayLength(vector<int>& nums, int k) {
        array<int, 32> setBitCount;
        int n = nums.size(), bitwiseOR = 0, left = 0, ret = INT_MAX; 
        
        for (int i = 0; i < n; i++) {
            bitwiseOR |= nums[i];
            
            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit)) {
                    setBitCount[bit]++;
                }
            }
            
            while (left <= i && bitwiseOR >= k) {
                ret = min(ret, i - left + 1);
                
                int temp = 0;
                for (int bit = 0; bit < 32; bit++) {
                    if (nums[left] & (1 << bit)) {
                        setBitCount[bit]--;
                    }
                    if (setBitCount[bit]) {
                        temp |= (1 << bit);
                    }
                }

                bitwiseOR = temp;
                left++; 
            }
        }
        
        return ret == INT_MAX ? -1 : ret;
    }
};

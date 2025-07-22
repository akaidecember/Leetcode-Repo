// Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description
// Description
// Given an array of integers
// nums
// and an integer
// limit
// , return the size of the longest
// non-empty
// subarray such that the absolute difference between any two elements of this subarray is less than or equal to
// limit
// .
// Example 1:
// Input:
// nums = [8,2,4,7], limit = 4
// Output:
// 2
// Explanation:
// All subarrays are: 
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4. 
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4. 
// Therefore, the size of the longest subarray is 2.
// Example 2:
// Input:
// nums = [10,1,2,4,7,2], limit = 5
// Output:
// 4
// Explanation:
// The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
// Example 3:
// Input:
// nums = [4,2,2,2,4,4,2,2], limit = 0
// Output:
// 3
// Constraints:
// 1 <= nums.length <= 10
// 5
// 1 <= nums[i] <= 10
// 9
// 0 <= limit <= 10
// 9

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> min_q, max_q; // Inc and dec.
        int left = 0, ret = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            while(!min_q.empty() && nums[i] < min_q.back()){
                min_q.pop_back();
            }
            while(!max_q.empty() && nums[i] > max_q.back()){
                max_q.pop_back();
            }
            min_q.push_back(nums[i]);
            max_q.push_back(nums[i]);
            while(max_q.front() - min_q.front() > limit){
                if(nums[left] == max_q.front()){
                    max_q.pop_front();
                }
                if(nums[left] == min_q.front()){
                    min_q.pop_front();
                }
                left++;
            }
            ret = max(ret, i - left + 1);
        }
        return ret;
    }
};

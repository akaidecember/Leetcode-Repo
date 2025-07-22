// Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description
// Description
// Given an integer array
// nums
// and an integer
// k
// , return
// the length of the shortest non-empty
// subarray
// of
// nums
// with a sum of at least
// k
// . If there is no such
// subarray
// , return
// -1
// .
// A
// subarray
// is a
// contiguous
// part of an array.
// Example 1:
// Input:
// nums = [1], k = 1
// Output:
// 1
// Example 2:
// Input:
// nums = [1,2], k = 4
// Output:
// -1
// Example 3:
// Input:
// nums = [2,-1,2], k = 3
// Output:
// 3
// Constraints:
// 1 <= nums.length <= 10
// 5
// -10
// 5
// <= nums[i] <= 10
// 5
// 1 <= k <= 10
// 9

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ret = INT_MAX, n = nums.size();
        long long curr_sum = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;

        for (int i = 0; i < n; i++){
            curr_sum += nums[i];

            if(curr_sum >= k){
                ret = min(ret, i + 1);
            }

            while (!minHeap.empty() && curr_sum - minHeap.top().first >= k){
                auto [_, end] = minHeap.top();
                minHeap.pop();
                ret = min(ret, i - end);
            }

            minHeap.push({curr_sum, i});
        }

        return (ret == INT_MAX) ? -1 : ret;
    }
};


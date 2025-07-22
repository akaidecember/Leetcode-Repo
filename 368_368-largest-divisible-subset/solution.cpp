// Link: https://leetcode.com/problems/largest-divisible-subset/description
// Description
// Given a set of
// distinct
// positive integers
// nums
// , return the largest subset
// answer
// such that every pair
// (answer[i], answer[j])
// of elements in this subset satisfies:
// answer[i] % answer[j] == 0
// , or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.
// Example 1:
// Input:
// nums = [1,2,3]
// Output:
// [1,2]
// Explanation:
// [1,3] is also accepted.
// Example 2:
// Input:
// nums = [1,2,4,8]
// Output:
// [1,2,4,8]
// Constraints:
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 10
// 9
// All the integers in
// nums
// are
// unique
// .

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mx = 1, start = 0;
        vector<int> length(n , 1), prev(n, -1), ret;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 and length[j] + 1 > length[i]){
                    length[i] = length[j] + 1;
                    prev[i] = j;
                }
            }
            if(length[i] > mx){
                mx = length[i];
                start = i;
            }
        }
        while(start != -1){
            ret.push_back(nums[start]);
            start = prev[start];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

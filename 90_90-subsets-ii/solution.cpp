// Link: https://leetcode.com/problems/subsets-ii/description
// Description
// Given an integer array
// nums
// that may contain duplicates, return
// all possible
// subsets
// (the power set)
// .
// The solution set
// must not
// contain duplicate subsets. Return the solution in
// any order
// .
// Example 1:
// Input:
// nums = [1,2,2]
// Output:
// [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:
// Input:
// nums = [0]
// Output:
// [[],[0]]
// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

#include<vector>
class Solution {
public:
    void helper(int i, vector<int> &nums, int n, vector<vector<int>> &ans, vector<int> &sub){
        ans.push_back(sub);
    
        for(int j = i; j < n; j++){
            if(j > i && nums[j] == nums[j-1]){
                continue;
            }

            sub.push_back(nums[j]);
            helper(j+1, nums, n, ans, sub);
            sub.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> sub;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        helper(0, nums, n, ret, sub);
        return ret;
    }
};



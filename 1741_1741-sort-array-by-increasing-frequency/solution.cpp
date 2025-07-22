// Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/description
// Description
// Given an array of integers
// nums
// , sort the array in
// increasing
// order based on the frequency of the values. If multiple values have the same frequency, sort them in
// decreasing
// order.
// Return the
// sorted array
// .
// Example 1:
// Input:
// nums = [1,1,2,2,2,3]
// Output:
// [3,1,1,2,2,2]
// Explanation:
// '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
// Example 2:
// Input:
// nums = [2,3,1,3,2]
// Output:
// [1,3,3,2,2]
// Explanation:
// '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
// Example 3:
// Input:
// nums = [-1,1,-6,4,5,-6,1,4,1]
// Output:
// [5,-1,4,4,-6,-6,1,1,1]
// Constraints:
// 1 <= nums.length <= 100
// -100 <= nums[i] <= 100

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for(const auto& n : nums){
            mp[n]++;
        }
        vector<pair<int,int>> v;
        copy(mp.begin(), mp.end(), back_inserter(v));
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        vector<int> ret;
        for(const auto& i : v){
            int temp = i.second;
            while(temp--)
                ret.push_back(i.first);
        }
        return ret;
    }
};

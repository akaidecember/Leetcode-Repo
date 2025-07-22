// Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/description
// Description
// Given a
// 0-indexed
// integer array
// nums
// of size
// n
// and two integers
// lower
// and
// upper
// , return
// the number of fair pairs
// .
// A pair
// (i, j)
// is
// fair
// if:
// 0 <= i < j < n
// , and
// lower <= nums[i] + nums[j] <= upper
// Example 1:
// Input:
// nums = [0,1,7,4,4,5], lower = 3, upper = 6
// Output:
// 6
// Explanation:
// There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
// Example 2:
// Input:
// nums = [1,7,9,2,5], lower = 11, upper = 11
// Output:
// 1
// Explanation:
// There is a single fair pair: (2,3).
// Constraints:
// 1 <= nums.length <= 10
// 5
// nums.length == n
// -10
// 9
// <= nums[i] <= 10
// 9
// -10
// 9
// <= lower <= upper <= 10
// 9

class Solution {
private:
    template <typename Iterator>
    Iterator binarySearch(Iterator start, Iterator end, int key, const bool isUpper) {
        int low = 0, high = end - start - 1; 
        while(low <= high){
            int mid = low + (high - low) / 2;
            if((isUpper and *(start + mid) <= key) || (!isUpper and *(start + mid) < key)){ 
                low = mid + 1;
            } 
            else{
                high = mid - 1; 
            }
        }

        return start + low; 
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end()); 
        long long ret = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto a = binarySearch(nums.begin() + i + 1, nums.end(), upper - nums[i], true) - nums.begin();
            auto b = binarySearch(nums.begin() + i + 1, nums.end(), lower - nums[i], false) - nums.begin();  
            ret += (a - b);
        }

        return ret;
    }
};

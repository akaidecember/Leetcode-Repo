// Link: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description
// Description
// You are given an array of integers
// nums
// of length
// n
// and a
// positive
// integer
// k
// .
// The
// power
// of an array is defined as:
// Its
// maximum
// element if
// all
// of its elements are
// consecutive
// and
// sorted
// in
// ascending
// order.
// -1 otherwise.
// You need to find the
// power
// of all
// subarrays
// of
// nums
// of size
// k
// .
// Return an integer array
// results
// of size
// n - k + 1
// , where
// results[i]
// is the
// power
// of
// nums[i..(i + k - 1)]
// .
// Example 1:
// Input:
// nums = [1,2,3,4,3,2,5], k = 3
// Output:
// [3,4,-1,-1,-1]
// Explanation:
// There are 5 subarrays of
// nums
// of size 3:
// [1, 2, 3]
// with the maximum element 3.
// [2, 3, 4]
// with the maximum element 4.
// [3, 4, 3]
// whose elements are
// not
// consecutive.
// [4, 3, 2]
// whose elements are
// not
// sorted.
// [3, 2, 5]
// whose elements are
// not
// consecutive.
// Example 2:
// Input:
// nums = [2,2,2,2,2], k = 4
// Output:
// [-1,-1]
// Example 3:
// Input:
// nums = [3,2,3,2,3,2], k = 2
// Output:
// [-1,3,-1,3,-1]
// Constraints:
// 1 <= n == nums.length <= 500
// 1 <= nums[i] <= 10
// 5
// 1 <= k <= n

class Solution {
public:
    template<typename Iterator>
    bool sorted(Iterator first, Iterator last) {
        for (auto it = first; it != last - 1; ++it) {
            if (*(it + 1) != *it + 1) {
                return false;
            }
        }

        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ret;
        int n = nums.size();

        if(n == 1){
            return {nums[0]};
        }

        for(int i = 0; i <= n - k; i++){
            auto temp = nums.begin() + i;
            if(sorted(temp, temp + k)){
                ret.push_back(*(temp + k - 1));
            }            
            else{
                ret.push_back(-1);
            }
        }
        return ret;
    }
};

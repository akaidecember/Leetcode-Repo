// Link: https://leetcode.com/problems/count-pairs-in-two-arrays/description
// Description
// Given two integer arrays
// nums1
// and
// nums2
// of length
// n
// , count the pairs of indices
// (i, j)
// such that
// i < j
// and
// nums1[i] + nums1[j] > nums2[i] + nums2[j]
// .
// Return
// the
// number of pairs
// satisfying the condition.
// Example 1:
// Input:
// nums1 = [2,1,2,1], nums2 = [1,2,1,2]
// Output:
// 1
// Explanation
// : The pairs satisfying the condition are:
// - (0, 2) where 2 + 2 > 1 + 1.
// Example 2:
// Input:
// nums1 = [1,10,6,2], nums2 = [1,4,1,5]
// Output:
// 5
// Explanation
// : The pairs satisfying the condition are:
// - (0, 1) where 1 + 10 > 1 + 4.
// - (0, 2) where 1 + 6 > 1 + 1.
// - (1, 2) where 10 + 6 > 4 + 1.
// - (1, 3) where 10 + 2 > 4 + 5.
// - (2, 3) where 6 + 2 > 1 + 5.
// Constraints:
// n == nums1.length == nums2.length
// 1 <= n <= 10
// 5
// 1 <= nums1[i], nums2[i] <= 10
// 5

class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        long long ret = 0;
        int n = nums1.size();
        vector<long long> diff(n);
        for(int i = 0; i < n; i++) diff[i] = nums1[i] - nums2[i];
        sort(diff.begin(), diff.end());
        int l = 0, r = n-1;
        while(l < r){
            int r_val = abs(diff[r]);
            int l_val = abs(diff[l]);
            if(r_val > l_val || diff[l] > 0) ret += (-l + (r--));
            else l++;
        }
        return ret;
    }
};

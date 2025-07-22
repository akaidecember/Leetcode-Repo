// Link: https://leetcode.com/problems/longest-square-streak-in-an-array/description
// Description
// You are given an integer array
// nums
// . A subsequence of
// nums
// is called a
// square streak
// if:
// The length of the subsequence is at least
// 2
// , and
// after
// sorting the subsequence, each element (except the first element) is the
// square
// of the previous number.
// Return
// the length of the
// longest square streak
// in
// nums
// , or return
// -1
// if there is no
// square streak
// .
// A
// subsequence
// is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// Example 1:
// Input:
// nums = [4,3,6,16,8,2]
// Output:
// 3
// Explanation:
// Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
// - 4 = 2 * 2.
// - 16 = 4 * 4.
// Therefore, [4,16,2] is a square streak.
// It can be shown that every subsequence of length 4 is not a square streak.
// Example 2:
// Input:
// nums = [2,3,5,6,7]
// Output:
// -1
// Explanation:
// There is no square streak in nums so return -1.
// Constraints:
// 2 <= nums.length <= 10
// 5
// 2 <= nums[i] <= 10
// 5

#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC optimize ("-ffloat-store")

auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> st;
        int ret = -1;

        for(const auto& n : nums) st.insert(n);

        for(auto& num : nums){
            int temp = 1;
            long long n = num;
            while(st.find(n * n) != st.end()){
                temp++;
                n = n * n;
                ret = max(ret, temp);
            }
        }
        return ret;
    }
};

// Link: https://leetcode.com/problems/count-good-triplets-in-an-array/description
// Description
// You are given two
// 0-indexed
// arrays
// nums1
// and
// nums2
// of length
// n
// , both of which are
// permutations
// of
// [0, 1, ..., n - 1]
// .
// A
// good triplet
// is a set of
// 3
// distinct
// values which are present in
// increasing order
// by position both in
// nums1
// and
// nums2
// . In other words, if we consider
// pos1
// v
// as the index of the value
// v
// in
// nums1
// and
// pos2
// v
// as the index of the value
// v
// in
// nums2
// , then a good triplet will be a set
// (x, y, z)
// where
// 0 <= x, y, z <= n - 1
// , such that
// pos1
// x
// < pos1
// y
// < pos1
// z
// and
// pos2
// x
// < pos2
// y
// < pos2
// z
// .
// Return
// the
// total number
// of good triplets
// .
// Example 1:
// Input:
// nums1 = [2,0,1,3], nums2 = [0,1,2,3]
// Output:
// 1
// Explanation:
// There are 4 triplets (x,y,z) such that pos1
// x
// < pos1
// y
// < pos1
// z
// . They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
// Out of those triplets, only the triplet (0,1,3) satisfies pos2
// x
// < pos2
// y
// < pos2
// z
// . Hence, there is only 1 good triplet.
// Example 2:
// Input:
// nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
// Output:
// 4
// Explanation:
// The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
// Constraints:
// n == nums1.length == nums2.length
// 3 <= n <= 10
// 5
// 0 <= nums1[i], nums2[i] <= n - 1
// nums1
// and
// nums2
// are permutations of
// [0, 1, ..., n - 1]
// .

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i;
        }
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) {
            mapped[i] = pos[nums1[i]];
        }
        vector<long long> left(n, 0), right(n, 0);
        vector<int> bit(n + 2, 0);
        for (int i = 0; i < n; ++i) {
            left[i] = query(bit, mapped[i]);
            update(bit, mapped[i] + 1, 1);
        }
        fill(bit.begin(), bit.end(), 0); 
        for (int i = n - 1; i >= 0; --i) {
            right[i] = query(bit, n) - query(bit, mapped[i] + 1);
            update(bit, mapped[i] + 1, 1);
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += left[i] * right[i];
        }
        return res;
    }

    void update(vector<int>& bit, int i, int val) {
        while (i < bit.size()) {
            bit[i] += val;
            i += i & -i; 
        }
    }

    int query(vector<int>& bit, int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i; 
        }
        return res;
    }
};

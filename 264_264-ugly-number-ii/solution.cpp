// Link: https://leetcode.com/problems/ugly-number-ii/description
// Description
// An
// ugly number
// is a positive integer whose prime factors are limited to
// 2
// ,
// 3
// , and
// 5
// .
// Given an integer
// n
// , return
// the
// n
// th
// ugly number
// .
// Example 1:
// Input:
// n = 10
// Output:
// 12
// Explanation:
// [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
// Example 2:
// Input:
// n = 1
// Output:
// 1
// Explanation:
// 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
// Constraints:
// 1 <= n <= 1690

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        int i = 0, j = 0, k = 0;
        for(int idx = 0; idx < n; idx++){
            int next = min(2 * v[i], min(3 * v[j], 5 * v[k]));
            v.push_back(next);
            if(next == 2 * v[i]) i++;
            if(next == 3 * v[j]) j++;
            if(next == 5 * v[k]) k++;
        }
        return v[n-1];
    }
};

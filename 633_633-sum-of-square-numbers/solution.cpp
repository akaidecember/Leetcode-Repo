// Link: https://leetcode.com/problems/sum-of-square-numbers/description
// Description
// Given a non-negative integer
// c
// , decide whether there're two integers
// a
// and
// b
// such that
// a
// 2
// + b
// 2
// = c
// .
// Example 1:
// Input:
// c = 5
// Output:
// true
// Explanation:
// 1 * 1 + 2 * 2 = 5
// Example 2:
// Input:
// c = 3
// Output:
// false
// Constraints:
// 0 <= c <= 2
// 31
// - 1

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0, right = sqrt(c), sum = 0;
        while(left <= right){
            long long temp = (left * left) + (right * right);
            if(temp == c){
                return true;
            }
            else if(temp > c){
                right--;
            }
            else if(temp < c){
                left++;
            }
        }
        return false;
    }
};

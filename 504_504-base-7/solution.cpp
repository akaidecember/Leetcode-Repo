// Link: https://leetcode.com/problems/base-7/description
// Description
// Given an integer
// num
// , return
// a string of its
// base 7
// representation
// .
// Example 1:
// Input:
// num = 100
// Output:
// "202"
// Example 2:
// Input:
// num = -7
// Output:
// "-10"
// Constraints:
// -10
// 7
// <= num <= 10
// 7

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";  
        }
    
        string ret;
        bool isNegative = (num < 0);
        num = abs(num);

        while(num > 0){
            int remainder = num % 7;
            ret += (remainder < 10) ? ('0' + remainder) : ('A' + remainder - 10);
            num /= 7;
        }

        if(isNegative){
            ret += '-';
        }
        
        reverse(ret.begin(), ret.end()); 
        return ret;
    }
};

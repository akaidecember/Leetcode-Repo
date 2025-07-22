// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description
// Description
// Given a
// valid parentheses string
// s
// , return the
// nesting depth
// of
// s
// . The nesting depth is the
// maximum
// number of nested parentheses.
// Example 1:
// Input:
// s = "(1+(2*3)+((8)/4))+1"
// Output:
// 3
// Explanation:
// Digit 8 is inside of 3 nested parentheses in the string.
// Example 2:
// Input:
// s = "(1)+((2))+(((3)))"
// Output:
// 3
// Explanation:
// Digit 3 is inside of 3 nested parentheses in the string.
// Example 3:
// Input:
// s = "()(())((()()))"
// Output:
// 3
// Constraints:
// 1 <= s.length <= 100
// s
// consists of digits
// 0-9
// and characters
// '+'
// ,
// '-'
// ,
// '*'
// ,
// '/'
// ,
// '('
// , and
// ')'
// .
// It is guaranteed that parentheses expression
// s
// is a VPS.

class Solution {
public:
    int maxDepth(string s) {
        if(s == ""){
            return 0;
        }
        stack<char> stk;
        int count = 0 , mx = 0;
        for(char c : s){
            if(c == '(' || c == ')'){
                stk.push(c);
            }
        }
        while(!stk.empty()){
            if(stk.top() == ')'){
                count++;
            }
            else if(stk.top() == '('){
                count--;
            }
            mx = max(mx, count);
            stk.pop();
        }
        return mx;
    }
};

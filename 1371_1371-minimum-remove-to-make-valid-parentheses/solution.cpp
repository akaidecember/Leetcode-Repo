// Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description
// Description
// Given a string
// s
// of
// '('
// ,
// ')'
// and lowercase English characters.
// Your task is to remove the minimum number of parentheses (
// '('
// or
// ')'
// , in any positions ) so that the resulting
// parentheses string
// is valid and return
// any
// valid string.
// Formally, a
// parentheses string
// is valid if and only if:
// It is the empty string, contains only lowercase characters, or
// It can be written as
// AB
// (
// A
// concatenated with
// B
// ), where
// A
// and
// B
// are valid strings, or
// It can be written as
// (A)
// , where
// A
// is a valid string.
// Example 1:
// Input:
// s = "lee(t(c)o)de)"
// Output:
// "lee(t(c)o)de"
// Explanation:
// "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
// Example 2:
// Input:
// s = "a)b(c)d"
// Output:
// "ab(c)d"
// Example 3:
// Input:
// s = "))(("
// Output:
// ""
// Explanation:
// An empty string is also valid.
// Constraints:
// 1 <= s.length <= 10
// 5
// s[i]
// is either
// '('
// ,
// ')'
// , or lowercase English letter.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s == ""){
            return s;
        }
        string ret;
        int open = 0;
        stack<char> stk;
        for(char c : s){
            if(c != ')'){
                if(c == '('){
                    open++;
                }
                stk.push(c);
            }
            else{
                if(open > 0){
                    open--;
                    stk.push(c);
                }
            }
        }
        while(!stk.empty()){
            char c = stk.top();
            stk.pop();
            if(open > 0 && c == '('){
                open--;
            }
            else{
                ret += c;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

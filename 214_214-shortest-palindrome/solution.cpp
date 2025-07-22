// Link: https://leetcode.com/problems/shortest-palindrome/description
// Description
// You are given a string
// s
// . You can convert
// s
// to a
// palindrome
// by adding characters in front of it.
// Return
// the shortest palindrome you can find by performing this transformation
// .
// Example 1:
// Input:
// s = "aacecaaa"
// Output:
// "aaacecaaa"
// Example 2:
// Input:
// s = "abcd"
// Output:
// "dcbabcd"
// Constraints:
// 0 <= s.length <= 5 * 10
// 4
// s
// consists of lowercase English letters only.

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size(), j = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == s[j]){
                j++;
            }
        }
        if(j == n){
            return s;
        }
        string suffix = s.substr(j);
        string prefix = suffix;
        reverse(prefix.begin(), prefix.end());
        return prefix + shortestPalindrome(s.substr(0, j)) + suffix;
    }
};

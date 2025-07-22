// Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description
// Description
// Given a string
// s
// , return
// the number of
// unique palindromes of length three
// that are a
// subsequence
// of
// s
// .
// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted
// once
// .
// A
// palindrome
// is a string that reads the same forwards and backwards.
// A
// subsequence
// of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example,
// "ace"
// is a subsequence of
// "
// a
// b
// c
// d
// e
// "
// .
// Example 1:
// Input:
// s = "aabca"
// Output:
// 3
// Explanation:
// The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "
// a
// a
// b
// c
// a
// ")
// - "aaa" (subsequence of "
// aa
// bc
// a
// ")
// - "aca" (subsequence of "
// a
// ab
// ca
// ")
// Example 2:
// Input:
// s = "adc"
// Output:
// 0
// Explanation:
// There are no palindromic subsequences of length 3 in "adc".
// Example 3:
// Input:
// s = "bbcbaba"
// Output:
// 4
// Explanation:
// The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "
// bb
// c
// b
// aba")
// - "bcb" (subsequence of "
// b
// b
// cb
// aba")
// - "bab" (subsequence of "
// b
// bcb
// ab
// a")
// - "aba" (subsequence of "bbcb
// aba
// ")
// Constraints:
// 3 <= s.length <= 10
// 5
// s
// consists of only lowercase English letters.

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> R(26,0);
        for(auto &u : s)
        {
            R[u-'a']++;
        }
        vector<int> L(26, 0);
        
        unordered_set<int> S;
        
        for(int i = 0; i < s.length(); i++)
        {
            int t = s[i] - 'a';
            R[t]--;
            for(int j = 0; j < 26; j++)
            {
                if(L[j] > 0 && R[j] > 0)
                {
                    S.insert(26*t + j);
                }
            }
            L[t]++;
        }
        
        return S.size();
    }
};

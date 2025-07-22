// Link: https://leetcode.com/problems/construct-k-palindrome-strings/description
// Description
// Given a string
// s
// and an integer
// k
// , return
// true
// if you can use all the characters in
// s
// to construct
// non-empty
// k
// palindrome strings
// or
// false
// otherwise.
// Example 1:
// Input:
// s = "annabelle", k = 2
// Output:
// true
// Explanation:
// You can construct two palindromes using all characters in s.
// Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
// Example 2:
// Input:
// s = "leetcode", k = 3
// Output:
// false
// Explanation:
// It is impossible to construct 3 palindromes using all the characters of s.
// Example 3:
// Input:
// s = "true", k = 4
// Output:
// true
// Explanation:
// The only possible solution is to put each character in a separate string.
// Constraints:
// 1 <= s.length <= 10
// 5
// s
// consists of lowercase English letters.
// 1 <= k <= 10
// 5

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k){
            return false;
        }
        
        vector<int> freq(26, 0);
        int odd_count = 0;

        for(const auto& c : s){
            freq[c - 97]++;
        }

        for(const auto& f : freq){
            if(f % 2 != 0){
                odd_count++;
            }
        }

        return (odd_count > k) ? false : true;
    }
};

// Link: https://leetcode.com/problems/number-of-wonderful-substrings/description
// Description
// A
// wonderful
// string is a string where
// at most one
// letter appears an
// odd
// number of times.
// For example,
// "ccjjc"
// and
// "abab"
// are wonderful, but
// "ab"
// is not.
// Given a string
// word
// that consists of the first ten lowercase English letters (
// 'a'
// through
// 'j'
// ), return
// the
// number of wonderful non-empty substrings
// in
// word
// . If the same substring appears multiple times in
// word
// , then count
// each occurrence
// separately.
// A
// substring
// is a contiguous sequence of characters in a string.
// Example 1:
// Input:
// word = "aba"
// Output:
// 4
// Explanation:
// The four wonderful substrings are underlined below:
// - "
// a
// ba" -> "a"
// - "a
// b
// a" -> "b"
// - "ab
// a
// " -> "a"
// - "
// aba
// " -> "aba"
// Example 2:
// Input:
// word = "aabb"
// Output:
// 9
// Explanation:
// The nine wonderful substrings are underlined below:
// - "
// a
// abb" -> "a"
// - "
// aa
// bb" -> "aa"
// - "
// aab
// b" -> "aab"
// - "
// aabb
// " -> "aabb"
// - "a
// a
// bb" -> "a"
// - "a
// abb
// " -> "abb"
// - "aa
// b
// b" -> "b"
// - "aa
// bb
// " -> "bb"
// - "aab
// b
// " -> "b"
// Example 3:
// Input:
// word = "he"
// Output:
// 2
// Explanation:
// The two wonderful substrings are underlined below:
// - "
// h
// e" -> "h"
// - "h
// e
// " -> "e"
// Constraints:
// 1 <= word.length <= 10
// 5
// word
// consists of lowercase English letters from
// 'a'
// to
// 'j'
// .

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int mask = 0;
        long long ret = 0;
        for(const auto& c : word){
            int bit = c - 97;
            mask ^= (1 << bit);
            ret += mp.find(mask) != mp.end() ? mp[mask] : 0;
            mp[mask] = (mp.find(mask) != mp.end() ? mp[mask] : 0) + 1;
            for(int i = 0; i < 10; i++)
                ret += mp.find(mask) != mp.end() ? mp[mask ^ (1 << i)] : 0;
        }
        return ret;
    }
};

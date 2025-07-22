// Link: https://leetcode.com/problems/permutation-in-string/description
// Description
// Given two strings
// s1
// and
// s2
// , return
// true
// if
// s2
// contains a
// permutation
// of
// s1
// , or
// false
// otherwise.
// In other words, return
// true
// if one of
// s1
// 's permutations is the substring of
// s2
// .
// Example 1:
// Input:
// s1 = "ab", s2 = "eidbaooo"
// Output:
// true
// Explanation:
// s2 contains one permutation of s1 ("ba").
// Example 2:
// Input:
// s1 = "ab", s2 = "eidboaoo"
// Output:
// false
// Constraints:
// 1 <= s1.length, s2.length <= 10
// 4
// s1
// and
// s2
// consist of lowercase English letters.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 26> mp1 = {}, mp2 = {};
        int n1 = s1.size(), n2 = s2.size();

        for(const auto& s : s1){
            mp1[s - 97]++;
        }

        for(int i = 0; i < n2; i++){
            if(i >= n1){
                if(equal(begin(mp1), end(mp1), begin(mp2))){
                    return true;
                }
                mp2[s2[i - n1] - 97]--;
            }
            mp2[s2[i] - 97]++;
        }

        return equal(begin(mp1), end(mp1), begin(mp2));
    }
};

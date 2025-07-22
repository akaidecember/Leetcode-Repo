// Link: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description
// Description
// Given a string
// s
// , return
// the length of the longest
// substring
// that contains at most
// two distinct characters
// .
// Example 1:
// Input:
// s = "eceba"
// Output:
// 3
// Explanation:
// The substring is "ece" which its length is 3.
// Example 2:
// Input:
// s = "ccaabbb"
// Output:
// 5
// Explanation:
// The substring is "aabbb" which its length is 5.
// Constraints:
// 1 <= s.length <= 10
// 5
// s
// consists of English letters.

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        // If string has two or less characters, the string itself is the ans
        if(n < 3) return n;
        int left = 0, right = 0, ret = 0;
        map<char, int> mp;
        while(right < n){
            mp[s[right]]++;
            // times when substring has more than 2 distinct chars
            while(mp.size() > 2){
                // Start incrementing the left pointer
                mp[s[left]]--;
                // Erase from map if none remaining
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            // Store the max ret
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};

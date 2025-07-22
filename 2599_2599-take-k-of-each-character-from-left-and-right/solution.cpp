// Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description
// Description
// You are given a string
// s
// consisting of the characters
// 'a'
// ,
// 'b'
// , and
// 'c'
// and a non-negative integer
// k
// . Each minute, you may take either the
// leftmost
// character of
// s
// , or the
// rightmost
// character of
// s
// .
// Return
// the
// minimum
// number of minutes needed for you to take
// at least
// k
// of each character, or return
// -1
// if it is not possible to take
// k
// of each character.
// Example 1:
// Input:
// s = "aabaaaacaabc", k = 2
// Output:
// 8
// Explanation:
// Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
// Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
// A total of 3 + 5 = 8 minutes is needed.
// It can be proven that 8 is the minimum number of minutes needed.
// Example 2:
// Input:
// s = "a", k = 1
// Output:
// -1
// Explanation:
// It is not possible to take one 'b' or 'c' so return -1.
// Constraints:
// 1 <= s.length <= 10
// 5
// s
// consists of only the letters
// 'a'
// ,
// 'b'
// , and
// 'c'
// .
// 0 <= k <= s.length

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>count(3, 0);

        for(char c : s){
            count[c - 'a']++;
        }

        if(*min_element(count.begin(), count.end()) < k){
            return -1;
        }

        int ret = INT_MAX, left = 0, n = s.length();

        for(int right = 0; right < n; right++){
            count[s[right] - 'a']--;

            while(*min_element(count.begin(), count.end()) < k){
                count[s[left++] - 'a']++;
            }

            ret = min(ret, static_cast<int>(s.length()) - (right - left + 1));
        }

        return ret;
    }
};

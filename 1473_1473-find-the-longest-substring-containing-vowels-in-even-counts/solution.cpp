// Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description
// Description
// Given the string
// s
// , return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
// Example 1:
// Input:
// s = "eleetminicoworoep"
// Output:
// 13
// Explanation:
// The longest substring is "leetminicowor" which contains two each of the vowels:
// e
// ,
// i
// and
// o
// and zero of the vowels:
// a
// and
// u
// .
// Example 2:
// Input:
// s = "leetcodeisgreat"
// Output:
// 5
// Explanation:
// The longest substring is "leetc" which contains two e's.
// Example 3:
// Input:
// s = "bcbcbc"
// Output:
// 6
// Explanation:
// In this case, the given string "bcbcbc" is the longest because all vowels:
// a
// ,
// e
// ,
// i
// ,
// o
// and
// u
// appear zero times.
// Constraints:
// 1 <= s.length <= 5 x 10^5
// s
// contains only lowercase English letters.

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size(), m = 0, i = 0;
        vector<char> v(26, -1), mask(n+1, 0);
        vector<int> vis(32, -1);
        v[0] = 0;
        v['e' - 97] = 1;
        v['i' - 97] = 2;
        v['o' - 97] = 3;
        v['u' - 97] = 4;
        vis[0] = 0;
        for(const auto& c : s){
            char temp = v[c - 97];
            char curr = mask[i+1] = mask[i] ^ (temp == -1 ? 0 : (1 << temp));
            if(vis[curr] == -1){
                vis[curr] = i + 1;
            }
            m = max(m, i + 1 - vis[curr]);
            i++;
        }
        return m;
    }
};

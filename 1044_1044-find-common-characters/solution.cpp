// Link: https://leetcode.com/problems/find-common-characters/description
// Description
// Given a string array
// words
// , return
// an array of all characters that show up in all strings within the
// words
// (including duplicates)
// . You may return the answer in
// any order
// .
// Example 1:
// Input:
// words = ["bella","label","roller"]
// Output:
// ["e","l","l"]
// Example 2:
// Input:
// words = ["cool","lock","cook"]
// Output:
// ["c","o"]
// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i]
// consists of lowercase English letters.

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26, INT_MAX);
        vector<string> ret;
        for (const auto& word : words){
            vector<int> cc(26, 0);
            for (char ch : word) cc[ch - 'a']++;
            for (int i = 0; i < 26; i++) v[i] = min(v[i], cc[i]);
        }
        for (int i = 0; i < 26; i++)
            while (v[i] > 0) {
                ret.push_back(string(1, 'a' + i));
                v[i]--;
            }
        return ret;
    }
};

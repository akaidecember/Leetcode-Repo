// Link: https://leetcode.com/problems/string-matching-in-an-array/description
// Description
// Given an array of string
// words
// , return all strings in
// words
// that are a
// substring
// of another word. You can return the answer in
// any order
// .
// Example 1:
// Input:
// words = ["mass","as","hero","superhero"]
// Output:
// ["as","hero"]
// Explanation:
// "as" is substring of "mass" and "hero" is substring of "superhero".
// ["hero","as"] is also a valid answer.
// Example 2:
// Input:
// words = ["leetcode","et","code"]
// Output:
// ["et","code"]
// Explanation:
// "et", "code" are substring of "leetcode".
// Example 3:
// Input:
// words = ["blue","green","bu"]
// Output:
// []
// Explanation:
// No string of words is substring of another string.
// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 30
// words[i]
// contains only lowercase English letters.
// All the strings of
// words
// are
// unique
// .

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ret;

        for(int i = 0;  i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j and words[j].find(words[i]) != string::npos){
                    ret.push_back(words[i]);
                    break;
                }
            }
        }

        return ret;
    }
};

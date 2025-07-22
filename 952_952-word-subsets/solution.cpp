// Link: https://leetcode.com/problems/word-subsets/description
// Description
// You are given two string arrays
// words1
// and
// words2
// .
// A string
// b
// is a
// subset
// of string
// a
// if every letter in
// b
// occurs in
// a
// including multiplicity.
// For example,
// "wrr"
// is a subset of
// "warrior"
// but is not a subset of
// "world"
// .
// A string
// a
// from
// words1
// is
// universal
// if for every string
// b
// in
// words2
// ,
// b
// is a subset of
// a
// .
// Return an array of all the
// universal
// strings in
// words1
// . You may return the answer in
// any order
// .
// Example 1:
// Input:
// words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output:
// ["facebook","google","leetcode"]
// Example 2:
// Input:
// words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["lc","eo"]
// Output:
// ["leetcode"]
// Example 3:
// Input:
// words1 = ["acaac","cccbb","aacbb","caacc","bcbbb"], words2 = ["c","cc","b"]
// Output:
// ["cccbb"]
// Constraints:
// 1 <= words1.length, words2.length <= 10
// 4
// 1 <= words1[i].length, words2[i].length <= 10
// words1[i]
// and
// words2[i]
// consist only of lowercase English letters.
// All the strings of
// words1
// are
// unique
// .

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> max_freq(26, 0), temp_freq(26, 0);
        vector<string> ret;

        for(const auto& word : words2){
            fill(temp_freq.begin(), temp_freq.end(), 0);
            for(const char c : word){
                temp_freq[c - 97]++;
            }
            for(int i = 0; i < 26; i++){
                max_freq[i] = max(max_freq[i], temp_freq[i]);
            }
        }

        for(const auto& word : words1){
            fill(temp_freq.begin(), temp_freq.end(), 0);
            for(const char c : word){
                temp_freq[c - 97]++;
            }
            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(max_freq[i] > temp_freq[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ret.push_back(word);
            }
        }

        return ret;
    }
};

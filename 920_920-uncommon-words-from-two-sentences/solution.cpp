// Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/description
// Description
// A
// sentence
// is a string of single-space separated words where each word consists only of lowercase letters.
// A word is
// uncommon
// if it appears exactly once in one of the sentences, and
// does not appear
// in the other sentence.
// Given two
// sentences
// s1
// and
// s2
// , return
// a list of all the
// uncommon words
// . You may return the answer in
// any order
// .
// Example 1:
// Input:
// s1 = "this apple is sweet", s2 = "this apple is sour"
// Output:
// ["sweet","sour"]
// Explanation:
// The word
// "sweet"
// appears only in
// s1
// , while the word
// "sour"
// appears only in
// s2
// .
// Example 2:
// Input:
// s1 = "apple apple", s2 = "banana"
// Output:
// ["banana"]
// Constraints:
// 1 <= s1.length, s2.length <= 200
// s1
// and
// s2
// consist of lowercase English letters and spaces.
// s1
// and
// s2
// do not have leading or trailing spaces.
// All the words in
// s1
// and
// s2
// are separated by a single space.

class Solution {
public:
    vector<string> split(string s){
        int start = 0, end;
        string token;
        vector<string> ret;
        while((end = s.find(" ", start)) != string::npos){
            token = s.substr(start, end - start);
            start = end + 1;
            ret.push_back(token);
        }
        ret.push_back(s.substr(start));
        return ret;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        vector<string> temp, ret;
        temp = split(s1);
        for(const auto& s : temp){
            mp[s]++;
        }
        temp.clear();
        temp = split(s2);
        for(const auto& s : temp){
            mp[s]++;
        }
        for(const auto& m : mp){
            if(m.second == 1){
                ret.push_back(m.first);
            }
        }
        return ret;
    }
};

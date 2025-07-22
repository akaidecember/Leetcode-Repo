// Link: https://leetcode.com/problems/keyboard-row/description
// Description
// Given an array of strings
// words
// , return
// the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below
// .
// Note
// that the strings are
// case-insensitive
// , both lowercased and uppercased of the same letter are treated as if they are at the same row.
// In the
// American keyboard
// :
// the first row consists of the characters
// "qwertyuiop"
// ,
// the second row consists of the characters
// "asdfghjkl"
// , and
// the third row consists of the characters
// "zxcvbnm"
// .
// Example 1:
// Input:
// words = ["Hello","Alaska","Dad","Peace"]
// Output:
// ["Alaska","Dad"]
// Explanation:
// Both
// "a"
// and
// "A"
// are in the 2nd row of the American keyboard due to case insensitivity.
// Example 2:
// Input:
// words = ["omk"]
// Output:
// []
// Example 3:
// Input:
// words = ["adsdf","sfd"]
// Output:
// ["adsdf","sfd"]
// Constraints:
// 1 <= words.length <= 20
// 1 <= words[i].length <= 100
// words[i]
// consists of English letters (both lowercase and uppercase).

class Solution {
private:
    string qrow = "qwertyuiop";
    string arow = "asdfghjkl";
    string zrow = "zxcvbnm";

public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        unordered_map<char, int> mp;

        for(const auto& c : qrow) mp[c] = 1;
        for(const auto& c : arow) mp[c] = 2;
        for(const auto& c : zrow) mp[c] = 3;

        for(const auto& w : words){
            string temp = w;
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            bool flag = true;
            for(int i = 0; i < temp.length() - 1; i++){
                if(mp[temp[i]] != mp[temp[i + 1]]){
                    flag = false;
                }
            }
            if(flag) ret.emplace_back(w);
        }

        return ret;
    }
};

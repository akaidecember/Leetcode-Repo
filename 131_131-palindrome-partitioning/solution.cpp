// Link: https://leetcode.com/problems/palindrome-partitioning/description
// Description
// Given a string
// s
// , partition
// s
// such that every
// substring
// of the partition is a
// palindrome
// . Return
// all possible palindrome partitioning of
// s
// .
// Example 1:
// Input:
// s = "aab"
// Output:
// [["a","a","b"],["aa","b"]]
// Example 2:
// Input:
// s = "a"
// Output:
// [["a"]]
// Constraints:
// 1 <= s.length <= 16
// s
// contains only lowercase English letters.

class Solution {
public:

    bool isPalindrome(string s){
        int n = s.size()-1, i = 0;
        while(i < n){
            if(s[i] != s[n]){
                return false;
            }
            i++;
            n--;
        }
        return true;
    }

    void partition(string s, vector<vector<string>> &ret, int idx, vector<string> t = vector<string>()){
        // if size is equal to idx, then reached the end or singular
        if(s.size() == idx){
            ret.push_back(t);
            return;
        }
        int n = s.size();
        for(int i = idx; i < n; i++){
            // For the size of the string, try all substrings
            string sub1 = s.substr(idx, i-idx+1);
            if(isPalindrome(sub1)){
                t.push_back({sub1});
                // Advance the start point for sub strings
                partition(s, ret, i+1, t);
                t.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        partition(s, ret, 0);
        return ret;
    }
};

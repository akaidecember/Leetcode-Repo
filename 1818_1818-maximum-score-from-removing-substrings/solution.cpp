// Link: https://leetcode.com/problems/maximum-score-from-removing-substrings/description
// Description
// You are given a string
// s
// and two integers
// x
// and
// y
// . You can perform two types of operations any number of times.
// Remove substring
// "ab"
// and gain
// x
// points.
// For example, when removing
// "ab"
// from
// "c
// ab
// xbae"
// it becomes
// "cxbae"
// .
// Remove substring
// "ba"
// and gain
// y
// points.
// For example, when removing
// "ba"
// from
// "cabx
// ba
// e"
// it becomes
// "cabxe"
// .
// Return
// the maximum points you can gain after applying the above operations on
// s
// .
// Example 1:
// Input:
// s = "cdbcbbaaabab", x = 4, y = 5
// Output:
// 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaa
// ba
// b". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaa
// ab
// ". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcb
// ba
// a". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbc
// ba
// ". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.
// Example 2:
// Input:
// s = "aabbaaxybbaabb", x = 5, y = 4
// Output:
// 20
// Constraints:
// 1 <= s.length <= 10
// 5
// 1 <= x, y <= 10
// 4
// s
// consists of lowercase English letters.

class Solution {
public:
    int helper(string &s, const vector<char> &p, int score){
        int ret = 0;
        vector<char> stk;
        for(const char& c : s){
            if(c == p[1] && !stk.empty() && stk.back() == p[0]){
                stk.pop_back();
                ret += score;
            }
            else{
                stk.push_back(c);
            }
        }
        s = string(stk.begin(), stk.end());
        return ret;
    }

    int maximumGain(string s, int x, int y) {
        int ret = 0;
        vector<char> t1 = {'a','b'}, t2 = {'b','a'};
        ret += helper(s, (x > y)?t1:t2, max(x,y));
        ret += helper(s, (x > y)?t2:t1, min(x,y));
        return ret;
    }
};

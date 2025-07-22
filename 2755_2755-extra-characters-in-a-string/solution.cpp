// Link: https://leetcode.com/problems/extra-characters-in-a-string/description
// Description
// You are given a
// 0-indexed
// string
// s
// and a dictionary of words
// dictionary
// . You have to break
// s
// into one or more
// non-overlapping
// substrings such that each substring is present in
// dictionary
// . There may be some
// extra characters
// in
// s
// which are not present in any of the substrings.
// Return
// the
// minimum
// number of extra characters left over if you break up
// s
// optimally.
// Example 1:
// Input:
// s = "leetscode", dictionary = ["leet","code","leetcode"]
// Output:
// 1
// Explanation:
// We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.
// Example 2:
// Input:
// s = "sayhelloworld", dictionary = ["hello","world"]
// Output:
// 3
// Explanation:
// We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
// Constraints:
// 1 <= s.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i]
// and
// s
// consists of only lowercase English letters
// dictionary
// contains distinct words

class Solution {
public:
    int dfs(int i, string s, map<int,int> &dp, set<string> &st){
        int n = s.size();
        if(dp.find(i) != dp.end()){
            return dp[i];
        }
        int ret = 1 + dfs(i + 1, s, dp, st);
        for(int j = i; j < n; j++){
            if(st.find(s.substr(i, j - i + 1)) != st.end()){
                ret = min(ret, dfs(j + 1, s, dp, st));
            }
        }
        dp[i] = ret;
        return ret;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st(dictionary.begin(), dictionary.end());
        map<int, int> dp;
        dp[s.size()] = 0;
        return dfs(0, s, dp, st);
    }
};

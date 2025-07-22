// Link: https://leetcode.com/problems/plates-between-candles/description
// Description
// There is a long table with a line of plates and candles arranged on top of it. You are given a
// 0-indexed
// string
// s
// consisting of characters
// '*'
// and
// '|'
// only, where a
// '*'
// represents a
// plate
// and a
// '|'
// represents a
// candle
// .
// You are also given a
// 0-indexed
// 2D integer array
// queries
// where
// queries[i] = [left
// i
// , right
// i
// ]
// denotes the
// substring
// s[left
// i
// ...right
// i
// ]
// (
// inclusive
// ). For each query, you need to find the
// number
// of plates
// between candles
// that are
// in the substring
// . A plate is considered
// between candles
// if there is at least one candle to its left
// and
// at least one candle to its right
// in the substring
// .
// For example,
// s = "||**||**|*"
// , and a query
// [3, 8]
// denotes the substring
// "*||
// **
// |"
// . The number of plates between candles in this substring is
// 2
// , as each of the two plates has at least one candle
// in the substring
// to its left
// and
// right.
// Return
// an integer array
// answer
// where
// answer[i]
// is the answer to the
// i
// th
// query
// .
// Example 1:
// Input:
// s = "**|**|***|", queries = [[2,5],[5,9]]
// Output:
// [2,3]
// Explanation:
// - queries[0] has two plates between candles.
// - queries[1] has three plates between candles.
// Example 2:
// Input:
// s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
// Output:
// [9,0,0,0,0]
// Explanation:
// - queries[0] has nine plates between candles.
// - The other queries have zero plates between candles.
// Constraints:
// 3 <= s.length <= 10
// 5
// s
// consists of
// '*'
// and
// '|'
// characters.
// 1 <= queries.length <= 10
// 5
// queries[i].length == 2
// 0 <= left
// i
// <= right
// i
// < s.length

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size(), count = 0, m = queries.size();
        vector<int> v(n, 0), cp, ret;
        for(int i = 0; i < n; i++){
            if(s[i] == '*') count++;
            if(s[i] == '|') cp.push_back(i);
            v[i] = count;
        }
        for(int i = 0; i < m; i++){
            int l = lower_bound(cp.begin(), cp.end(), queries[i][0]) - cp.begin();
            int r = upper_bound(cp.begin(), cp.end(), queries[i][1]) - cp.begin();
            if(l < 0 || l >= cp.size() || r <= 0 || r > cp.size() || v[cp[r - 1]] - v[cp[l]] < 0){
                ret.push_back(0);
            }
            else{
                ret.push_back(v[cp[r - 1]] - v[cp[l]]);
            }
        }
        return ret;
    }
};

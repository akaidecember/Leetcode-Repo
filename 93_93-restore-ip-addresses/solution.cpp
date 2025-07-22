// Link: https://leetcode.com/problems/restore-ip-addresses/description
// Description
// A
// valid IP address
// consists of exactly four integers separated by single dots. Each integer is between
// 0
// and
// 255
// (
// inclusive
// ) and cannot have leading zeros.
// For example,
// "0.1.2.201"
// and
// "192.168.1.1"
// are
// valid
// IP addresses, but
// "0.011.255.245"
// ,
// "192.168.1.312"
// and
// "192.168@1.1"
// are
// invalid
// IP addresses.
// Given a string
// s
// containing only digits, return
// all possible valid IP addresses that can be formed by inserting dots into
// s
// . You are
// not
// allowed to reorder or remove any digits in
// s
// . You may return the valid IP addresses in
// any
// order.
// Example 1:
// Input:
// s = "25525511135"
// Output:
// ["255.255.11.135","255.255.111.35"]
// Example 2:
// Input:
// s = "0000"
// Output:
// ["0.0.0.0"]
// Example 3:
// Input:
// s = "101023"
// Output:
// ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// Constraints:
// 1 <= s.length <= 20
// s
// consists of digits only.

class Solution {
public:
    void backtrack(int i, int dots, string currIP, string s, vector<string> &ret){
        int n = s.size();
        if(dots == 4 && i == n){
            ret.push_back(currIP.substr(0, currIP.size() - 1));
            return;
        }
        for(int j = i; j < min(i + 3, n); ++j){
            string str = s.substr(i, j - i + 1);
            int temp = atoi(str.c_str());
            if(temp < 256 && (i == j || s[i] != '0')){
                backtrack(j + 1, dots + 1, currIP + str + '.', s, ret);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        int n = s.size();
        if (n > 12) return ret;
        backtrack(0, 0, "", s, ret);
        return ret;
    }
};

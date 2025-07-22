// Link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description
// Description
// You are given a string
// s
// that consists of lowercase English letters.
// A string is called
// special
// if it is made up of only a single character. For example, the string
// "abc"
// is not special, whereas the strings
// "ddd"
// ,
// "zz"
// , and
// "f"
// are special.
// Return
// the length of the
// longest special substring
// of
// s
// which occurs
// at least thrice
// ,
// or
// -1
// if no special substring occurs at least thrice
// .
// A
// substring
// is a contiguous
// non-empty
// sequence of characters within a string.
// Example 1:
// Input:
// s = "aaaa"
// Output:
// 2
// Explanation:
// The longest special substring which occurs thrice is "aa": substrings "
// aa
// aa", "a
// aa
// a", and "aa
// aa
// ".
// It can be shown that the maximum length achievable is 2.
// Example 2:
// Input:
// s = "abcdef"
// Output:
// -1
// Explanation:
// There exists no special substring which occurs at least thrice. Hence return -1.
// Example 3:
// Input:
// s = "abcaba"
// Output:
// 1
// Explanation:
// The longest special substring which occurs thrice is "a": substrings "
// a
// bcaba", "abc
// a
// ba", and "abcab
// a
// ".
// It can be shown that the maximum length achievable is 1.
// Constraints:
// 3 <= s.length <= 50
// s
// consists of only lowercase English letters.

class Solution {
private:
    array<int, 26> arr;

public:
    bool helper(const string& s, int idx){
        int n = s.length(), temp = 0;
        arr.fill(0);

        for(int i = 0; i < n; i++){
            while(s[temp] != s[i]){
                temp++;
            }

            if(i - temp + 1 >= idx){
                arr[s[i] - 97]++;
            }

            if(arr[s[i] - 97] > 2){
                return true;
            }
        }

        return false;
    }

    int maximumLength(string s) {
        int n = s.length(), left = 1, right = n;

        if(!helper(s, left)){
            return -1;
        }

        while(left + 1 < right){
            int mid = left + (right - left) / 2;

            if(helper(s, mid)){
                left = mid;
            }
            else{
                right = mid;
            }

        }

        return left;
    }
};

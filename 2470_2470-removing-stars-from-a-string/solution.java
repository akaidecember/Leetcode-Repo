// Link: https://leetcode.com/problems/removing-stars-from-a-string/description
// Description
// You are given a string
// s
// , which contains stars
// *
// .
// In one operation, you can:
// Choose a star in
// s
// .
// Remove the closest
// non-star
// character to its
// left
// , as well as remove the star itself.
// Return
// the string after
// all
// stars have been removed
// .
// Note:
// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.
// Example 1:
// Input:
// s = "leet**cod*e"
// Output:
// "lecoe"
// Explanation:
// Performing the removals from left to right:
// - The closest character to the 1
// st
// star is 't' in "lee
// t
// **cod*e". s becomes "lee*cod*e".
// - The closest character to the 2
// nd
// star is 'e' in "le
// e
// *cod*e". s becomes "lecod*e".
// - The closest character to the 3
// rd
// star is 'd' in "leco
// d
// *e". s becomes "lecoe".
// There are no more stars, so we return "lecoe".
// Example 2:
// Input:
// s = "erase*****"
// Output:
// ""
// Explanation:
// The entire string is removed, so we return an empty string.
// Constraints:
// 1 <= s.length <= 10
// 5
// s
// consists of lowercase English letters and stars
// *
// .
// The operation above can be performed on
// s
// .

class Solution {
    public String removeStars(String s) {
        StringBuilder str = new StringBuilder();

        for(char c : s.toCharArray()){
            if(c == '*'){
                str.deleteCharAt(str.length() - 1);
            }
            else{
                str.append(c);
            }
        }

        return str.toString();
    }
}
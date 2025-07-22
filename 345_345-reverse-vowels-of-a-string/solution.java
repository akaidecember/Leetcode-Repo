// Link: https://leetcode.com/problems/reverse-vowels-of-a-string/description
// Description
// Given a string
// s
// , reverse only all the vowels in the string and return it.
// The vowels are
// 'a'
// ,
// 'e'
// ,
// 'i'
// ,
// 'o'
// , and
// 'u'
// , and they can appear in both lower and upper cases, more than once.
// Example 1:
// Input:
// s = "IceCreAm"
// Output:
// "AceCreIm"
// Explanation:
// The vowels in
// s
// are
// ['I', 'e', 'e', 'A']
// . On reversing the vowels, s becomes
// "AceCreIm"
// .
// Example 2:
// Input:
// s = "leetcode"
// Output:
// "leotcede"
// Constraints:
// 1 <= s.length <= 3 * 10
// 5
// s
// consist of
// printable ASCII
// characters.

class Solution {
    private Boolean isVowel(char ch){
        return "AEIOUaeiou".indexOf(ch) != -1;
    }
    public String reverseVowels(String s) {
        int start = 0, end = s.length();
        StringBuilder ret = new StringBuilder(s);
        
        for(int i = start, j = end - 1; i < j;){
            if(isVowel(ret.charAt(i)) && isVowel(ret.charAt(j))){
                char temp = ret.charAt(i);
                ret.setCharAt(i, ret.charAt(j));
                ret.setCharAt(j, temp);
                i++;
                j--;
            }
            else{
                if(!isVowel(ret.charAt(i))){
                    i++;
                }
                if(!isVowel(ret.charAt(j))){
                    j--;
                }
            }
        }

        return ret.toString();
    }
}
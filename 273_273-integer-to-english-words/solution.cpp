// Link: https://leetcode.com/problems/integer-to-english-words/description
// Description
// Convert a non-negative integer
// num
// to its English words representation.
// Example 1:
// Input:
// num = 123
// Output:
// "One Hundred Twenty Three"
// Example 2:
// Input:
// num = 12345
// Output:
// "Twelve Thousand Three Hundred Forty Five"
// Example 3:
// Input:
// num = 1234567
// Output:
// "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// Constraints:
// 0 <= num <= 2
// 31
// - 1

class Solution {
public:
    string helper(int num) {
        vector<string> single = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        string ret = "";
        if (num >= 100) {
            ret += single[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            ret += tens[num / 10] + " ";
            num %= 10;
        } else if (num >= 10) {
            ret += teens[num - 10] + " ";
            return ret;
        }
        if (num > 0) {
            ret += single[num] + " ";
        }
        return ret;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<string> bigNums = {"Thousand", "Million", "Billion"};
        string ret = helper(num % 1000);
        num /= 1000;
        for (int i = 0; i < bigNums.size(); i++) {
            if (num % 1000 > 0) {
                ret = helper(num % 1000) + bigNums[i] + " " + ret;
            }
            num /= 1000;
        }
        while (!ret.empty() && ret.back() == ' ') {
            ret.pop_back(); 
        }
        return ret;
    }
};

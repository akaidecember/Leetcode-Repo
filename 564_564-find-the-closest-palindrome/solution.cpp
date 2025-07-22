// Link: https://leetcode.com/problems/find-the-closest-palindrome/description
// Description
// Given a string
// n
// representing an integer, return
// the closest integer (not including itself), which is a palindrome
// . If there is a tie, return
// the smaller one
// .
// The closest is defined as the absolute difference minimized between two integers.
// Example 1:
// Input:
// n = "123"
// Output:
// "121"
// Example 2:
// Input:
// n = "1"
// Output:
// "0"
// Explanation:
// 0 and 2 are the closest palindromes but we return the smallest which is 0.
// Constraints:
// 1 <= n.length <= 18
// n
// consists of only digits.
// n
// does not have leading zeros.
// n
// is representing an integer in the range
// [1, 10
// 18
// - 1]
// .

class Solution {
public:
    string nearestPalindromic(string n) {
        if (n == "1") return "0";
        long long num = stoll(n);
        int len = n.size();
        long long smallest = pow(10, len - 1) - 1, largest = pow(10, len) + 1;
        string left = n.substr(0, (len + 1) / 2);
        vector<long long> v;

        for(int i = -1; i <= 1; i++){
            string newLeft = to_string(stoll(left) + i);
            string palindrome = newLeft + string(newLeft.rbegin() + (len % 2), newLeft.rend());
            v.push_back(stoll(palindrome));
        }
        v.push_back(smallest);
        v.push_back(largest);
        long long closest = -1;
        for(long long candidate : v){
            if(candidate == num){
                continue; 
            }
            if(closest == -1 || abs(candidate - num) < abs(closest - num) ||
                (abs(candidate - num) == abs(closest - num) && candidate < closest)){
                closest = candidate;
            }
        }
        return to_string(closest);
    }
};

// Link: https://leetcode.com/problems/find-the-count-of-good-integers/description
// Description
// You are given two
// positive
// integers
// n
// and
// k
// .
// An integer
// x
// is called
// k-palindromic
// if:
// x
// is a
// palindrome
// .
// x
// is divisible by
// k
// .
// An integer is called
// good
// if its digits can be
// rearranged
// to form a
// k-palindromic
// integer. For example, for
// k = 2
// , 2020 can be rearranged to form the
// k-palindromic
// integer 2002, whereas 1010 cannot be rearranged to form a
// k-palindromic
// integer.
// Return the count of
// good
// integers containing
// n
// digits.
// Note
// that
// any
// integer must
// not
// have leading zeros,
// neither
// before
// nor
// after rearrangement. For example, 1010
// cannot
// be rearranged to form 101.
// Example 1:
// Input:
// n = 3, k = 5
// Output:
// 27
// Explanation:
// Some
// of the good integers are:
// 551 because it can be rearranged to form 515.
// 525 because it is already k-palindromic.
// Example 2:
// Input:
// n = 1, k = 4
// Output:
// 2
// Explanation:
// The two good integers are 4 and 8.
// Example 3:
// Input:
// n = 5, k = 6
// Output:
// 2468
// Constraints:
// 1 <= n <= 10
// 1 <= k <= 9

class Solution {
private:
    long long ret = 0;
    set<map<int,int>> visited;

public:
    long long fact(int n, long long f = 1) {
        for (int i = 2; i <= n; i++){
            f *= i;
        }
        return f;
    }

    long long totalPermutations(map<int, int>& mp, int n) {
        long long ret = fact(n);
        for (auto& m : mp) {
            ret /= fact(m.second);
        }
        return ret;
    }

    long long permsWithZero(map<int, int> mp, int n) {
        return mp[0] == 0 ? 0 : ([&]() {
            mp[0]--;
            long long ret = fact(n - 1);
            for (auto& m : mp)
                ret /= fact(m.second);
            return ret;
        }());
    }

    void generatePalindrome(vector<int>& palindrome, int left, int right, int k, int n){
        if(left > right) {
            long long palindromeValue = 0;
            for_each(palindrome.begin(), palindrome.end(), [&](int d) {
                palindromeValue = palindromeValue * 10 + d;
            });
            if(palindromeValue % k == 0) {
                map<int,int> digitMap;
                for(long long i = palindromeValue; i; i /= 10){
                    digitMap[i % 10]++;
                }
                if(!visited.count(digitMap)){
                    ret += totalPermutations(digitMap, n) - permsWithZero(digitMap, n);
                    visited.insert(digitMap);
                }
            }
            return;
        }
        for (int i = (left == 0 ? 1 : 0); i <= 9; i++) {
            palindrome[left] = palindrome[right] = i;
            generatePalindrome(palindrome, left + 1, right - 1, k, n);
        }

    }

    long long countGoodIntegers(int n, int k) {
        vector<int> palindrome(n);
        generatePalindrome(palindrome, 0, n - 1, k, n);
        return ret;
    }
};

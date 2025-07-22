// Link: https://leetcode.com/problems/closest-prime-numbers-in-range/description
// Description
// Given two positive integers
// left
// and
// right
// , find the two integers
// num1
// and
// num2
// such that:
// left <= num1 < num2 <= right
// .
// Both
// num1
// and
// num2
// are
// prime numbers
// .
// num2 - num1
// is the
// minimum
// amongst all other pairs satisfying the above conditions.
// Return the positive integer array
// ans = [num1, num2]
// . If there are multiple pairs satisfying these conditions, return the one with the
// smallest
// num1
// value. If no such numbers exist, return
// [-1, -1]
// .
// Example 1:
// Input:
// left = 10, right = 19
// Output:
// [11,13]
// Explanation:
// The prime numbers between 10 and 19 are 11, 13, 17, and 19.
// The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
// Since 11 is smaller than 17, we return the first pair.
// Example 2:
// Input:
// left = 4, right = 6
// Output:
// [-1,-1]
// Explanation:
// There exists only one prime number in the given range, so the conditions cannot be satisfied.
// Constraints:
// 1 <= left <= right <= 10
// 6

class Solution {
public:
    bool checkPrime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;  
        if (n % 2 == 0 || n % 3 == 0) return false;  

        for (int i = 5; i * i <= n; i += 6) {  
            if (n % i == 0 || n % (i + 2) == 0) 
                return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (checkPrime(i)) {
                primes.push_back(i);
            }
        }
        if (primes.size() < 2) return {-1, -1};
        int minDiff = INT_MAX;
        vector<int> result(2);
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i], primes[i + 1]};
            }
        }

        return result;
    }
};

// Link: https://leetcode.com/problems/count-the-number-of-ideal-arrays/description
// Description
// You are given two integers
// n
// and
// maxValue
// , which are used to describe an
// ideal
// array.
// A
// 0-indexed
// integer array
// arr
// of length
// n
// is considered
// ideal
// if the following conditions hold:
// Every
// arr[i]
// is a value from
// 1
// to
// maxValue
// , for
// 0 <= i < n
// .
// Every
// arr[i]
// is divisible by
// arr[i - 1]
// , for
// 0 < i < n
// .
// Return
// the number of
// distinct
// ideal arrays of length
// n
// . Since the answer may be very large, return it modulo
// 10
// 9
// + 7
// .
// Example 1:
// Input:
// n = 2, maxValue = 5
// Output:
// 10
// Explanation:
// The following are the possible ideal arrays:
// - Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
// - Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
// - Arrays starting with the value 3 (1 array): [3,3]
// - Arrays starting with the value 4 (1 array): [4,4]
// - Arrays starting with the value 5 (1 array): [5,5]
// There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
// Example 2:
// Input:
// n = 5, maxValue = 3
// Output:
// 11
// Explanation:
// The following are the possible ideal arrays:
// - Arrays starting with the value 1 (9 arrays): 
//    - With no other distinct values (1 array): [1,1,1,1,1] 
//    - With 2
// nd
// distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
//    - With 2
// nd
// distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
// - Arrays starting with the value 2 (1 array): [2,2,2,2,2]
// - Arrays starting with the value 3 (1 array): [3,3,3,3,3]
// There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.
// Constraints:
// 2 <= n <= 10
// 4
// 1 <= maxValue <= 10
// 4

class Solution {
private:
static const int MOD = 1e9 + 7;
typedef long long ll;
ll modpow(ll a, ll p) {
    ll res = 1;
    a %= MOD;
    while (p) {
        if (p & 1) res = res * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return res;
}
public:
    int idealArrays(int n, int maxValue) {
        vector<vector<int>> children(maxValue + 1);
        for (int v = 1; v <= maxValue; ++v) {
            for (int u = v * 2; u <= maxValue; u += v) {
                children[v].push_back(u);
            }
        }

        vector<ll> prev(maxValue + 1, 1), curr(maxValue + 1);
        vector<ll> S;  
        S.reserve(20);
        S.push_back(maxValue);  

        for (int l = 2; ; ++l) {
            ll sum = 0;
            for (int v = 1; v <= maxValue; ++v) {
                ll cnt = 0;
                for (int u : children[v]) {
                    cnt = (cnt + prev[u]) % MOD;
                }
                curr[v] = cnt;
                sum = (sum + cnt) % MOD;
            }
            if (sum == 0) break;
            S.push_back(sum);
            prev.swap(curr);
        }

        vector<ll> fact(n), invfact(n);
        fact[0] = 1;
        for (int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invfact[n - 1] = modpow(fact[n - 1], MOD - 2);
        for (int i = n - 1; i > 0; --i) invfact[i - 1] = invfact[i] * i % MOD;

        auto comb = [&](int a, int b) {
            if (b < 0 || b > a) return 0LL;
            return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
        };

        ll ans = 0;
        int Lmax = S.size();
        for (int l = 1; l <= Lmax; ++l) {
            ans = (ans + S[l - 1] * comb(n - 1, l - 1) % MOD) % MOD;
        }

        return (int)ans;
    }
};


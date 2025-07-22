// Link: https://leetcode.com/problems/apply-operations-to-maximize-score/description
// Description
// You are given an array
// nums
// of
// n
// positive integers and an integer
// k
// .
// Initially, you start with a score of
// 1
// . You have to maximize your score by applying the following operation at most
// k
// times:
// Choose any
// non-empty
// subarray
// nums[l, ..., r]
// that you haven't chosen previously.
// Choose an element
// x
// of
// nums[l, ..., r]
// with the highest
// prime score
// . If multiple such elements exist, choose the one with the smallest index.
// Multiply your score by
// x
// .
// Here,
// nums[l, ..., r]
// denotes the subarray of
// nums
// starting at index
// l
// and ending at the index
// r
// , both ends being inclusive.
// The
// prime score
// of an integer
// x
// is equal to the number of distinct prime factors of
// x
// . For example, the prime score of
// 300
// is
// 3
// since
// 300 = 2 * 2 * 3 * 5 * 5
// .
// Return
// the
// maximum possible score
// after applying at most
// k
// operations
// .
// Since the answer may be large, return it modulo
// 10
// 9
// + 7
// .
// Example 1:
// Input:
// nums = [8,3,9,3,8], k = 2
// Output:
// 81
// Explanation:
// To get a score of 81, we can apply the following operations:
// - Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
// - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
// It can be proven that 81 is the highest score one can obtain.
// Example 2:
// Input:
// nums = [19,12,14,6,10,18], k = 3
// Output:
// 4788
// Explanation:
// To get a score of 4788, we can apply the following operations: 
// - Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
// - Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
// - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
// It can be proven that 4788 is the highest score one can obtain.
// Constraints:
// 1 <= nums.length == n <= 10
// 5
// 1 <= nums[i] <= 10
// 5
// 1 <= k <= min(n * (n + 1) / 2, 10
// 9
// )

const int N=sqrt(100000);
vector<bool> isPrime(N+1, 1);
vector<int> prime;
long long num_idx[100000];
class Solution {
public:
    const static int mod = 1e9 + 7;
    constexpr static void Sieve() {
        if (!prime.empty()) return;
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                prime.push_back(i);
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = 0;
            }
        }
        for (int i = 2; i <= N; i++) {
            if (isPrime[i]) prime.push_back(i);
        }
    }

    static int prime_score(int x){
        if (x<=N && isPrime[x]) return 1;
        int xsqrt=sqrt(x);
        int cnt=0;
        for(int p: prime){
            if (p>xsqrt) break;
            if (x%p!=0) continue;
            while (x%p==0){
                x/=p;
            }
            cnt++;
        }
        cnt+=(x>1);
        return cnt;
    }

    inline static long long modPow(long long x, int exp) {
        long long ans= 1;
        while (exp>0) {
            if (exp&1) ans=ans*x % mod;
            x=x*x%mod;
            exp/=2;
        }
        return ans;
    }

    static int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        Sieve();

        vector<int> score(n), left(n), right(n);
        for (int i=0; i< n; i++) score[i] = prime_score(nums[i]);

        vector<int> st;
        for (int i=0; i < n; i++) {
            while (!st.empty() && score[i] > score[st.back()]) st.pop_back();
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && score[i] >= score[st.back()]) st.pop_back();
            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        for (int i = 0; i < n; i++)
            num_idx[i] = ((long long)nums[i]<<20) + i;

        sort(num_idx , num_idx+n , greater<>());

        long long ans = 1;
        for (int i = 0; i < n && k > 0; i++) {
            const long long nI=num_idx[i];
            const int x = nI>>20, idx = nI & ((1<<20)-1);
            const int exp = min((long long)(idx-left[idx]) * (right[idx]-idx), (long long)k);
            ans=ans*modPow(x, exp) % mod;
            k-=exp;
        }

        return ans;
    }
};

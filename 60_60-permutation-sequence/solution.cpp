// Link: https://leetcode.com/problems/permutation-sequence/description
// Description
// The set
// [1, 2, 3, ..., n]
// contains a total of
// n!
// unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for
// n = 3
// :
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given
// n
// and
// k
// , return the
// k
// th
// permutation sequence.
// Example 1:
// Input:
// n = 3, k = 3
// Output:
// "213"
// Example 2:
// Input:
// n = 4, k = 9
// Output:
// "2314"
// Example 3:
// Input:
// n = 3, k = 1
// Output:
// "123"
// Constraints:
// 1 <= n <= 9
// 1 <= k <= n!

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> seq;
        int fact = 1;
        for(int i = 1; i < n; i++){
            fact *= i;
            seq.push_back(i);
        }
        k--;
        seq.push_back(n);
        string ans = "";
        while(true){
            int temp = seq[k/fact];
            ans += to_string(temp);
            seq.erase(seq.begin() + k/fact);
            if(seq.size() <= 0){
                break;
            }
            k %= fact;
            fact /= seq.size();
        }
        return ans;
    }
};

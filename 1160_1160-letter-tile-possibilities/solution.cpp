// Link: https://leetcode.com/problems/letter-tile-possibilities/description
// Description
// You have
// n
// tiles
// , where each tile has one letter
// tiles[i]
// printed on it.
// Return
// the number of possible non-empty sequences of letters
// you can make using the letters printed on those
// tiles
// .
// Example 1:
// Input:
// tiles = "AAB"
// Output:
// 8
// Explanation:
// The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
// Example 2:
// Input:
// tiles = "AAABBC"
// Output:
// 188
// Example 3:
// Input:
// tiles = "V"
// Output:
// 1
// Constraints:
// 1 <= tiles.length <= 7
// tiles
// consists of uppercase English letters.

class Solution {
public:
    int Perm(int n, vector<int>& freq, int fz){
        if (n==1){
           return fz-count(freq.begin(), freq.end(), 0);
        }
        int ans=0;
        for (int i=0; i<fz; i++) {
            if (freq[i]>0) {
                freq[i]--; 
                ans += Perm(n-1, freq, fz);
                freq[i]++; 
            }
        }
        return ans;
    }
    int numTilePossibilities(string& tiles) {
        int sz = 0, tz = tiles.size();
        vector<int> freq(26, 0);
        for (char c : tiles)
            if (++freq[c-'A'] == 1) {
                sz++;
            }
        sort(freq.begin(), freq.end(), greater<int>());
        freq.resize(sz);

        int cnt=0;
        for (int len=1; len<=tz; len++) {
            cnt+= Perm(len, freq, sz);
        }

        return cnt;
    }
};

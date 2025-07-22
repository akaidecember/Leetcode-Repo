// Link: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description
// Description
// The
// bitwise AND
// of an array
// nums
// is the bitwise AND of all integers in
// nums
// .
// For example, for
// nums = [1, 5, 3]
// , the bitwise AND is equal to
// 1 & 5 & 3 = 1
// .
// Also, for
// nums = [7]
// , the bitwise AND is
// 7
// .
// You are given an array of positive integers
// candidates
// . Compute the
// bitwise AND
// for all possible
// combinations
// of elements in the
// candidates
// array.
// Return
// the size of the
// largest
// combination of
// candidates
// with a bitwise AND
// greater
// than
// 0
// .
// Example 1:
// Input:
// candidates = [16,17,71,62,12,24,14]
// Output:
// 4
// Explanation:
// The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.
// The size of the combination is 4.
// It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
// Note that more than one combination may have the largest size.
// For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.
// Example 2:
// Input:
// candidates = [8,8]
// Output:
// 2
// Explanation:
// The largest combination [8,8] has a bitwise AND of 8 & 8 = 8 > 0.
// The size of the combination is 2, so we return 2.
// Constraints:
// 1 <= candidates.length <= 10
// 5
// 1 <= candidates[i] <= 10
// 7

class Solution {
    public int largestCombination(int[] candidates) {
        int ret = 0;

        for(int i = 0; i < 32; i++){
            int pos = i;
            int count = (int) Arrays.stream(candidates)
                                       .filter(c -> (c & (1 << pos)) != 0)
                                       .count();

            ret = Math.max(ret, count); 
        }

        return ret;
    }
}
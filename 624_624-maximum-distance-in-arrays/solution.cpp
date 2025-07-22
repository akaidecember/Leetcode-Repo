// Link: https://leetcode.com/problems/maximum-distance-in-arrays/description
// Description
// You are given
// m
// arrays
// , where each array is sorted in
// ascending order
// .
// You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers
// a
// and
// b
// to be their absolute difference
// |a - b|
// .
// Return
// the maximum distance
// .
// Example 1:
// Input:
// arrays = [[1,2,3],[4,5],[1,2,3]]
// Output:
// 4
// Explanation:
// One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
// Example 2:
// Input:
// arrays = [[1],[1]]
// Output:
// 0
// Constraints:
// m == arrays.length
// 2 <= m <= 10
// 5
// 1 <= arrays[i].length <= 500
// -10
// 4
// <= arrays[i][j] <= 10
// 4
// arrays[i]
// is sorted in
// ascending order
// .
// There will be at most
// 10
// 5
// integers in all the arrays.

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            max_distance = max(max_distance, abs(arrays[i].back() - smallest));
            max_distance = max(max_distance, abs(biggest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }

        return max_distance;
    }
};

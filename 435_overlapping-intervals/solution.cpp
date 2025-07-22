// Link: https://leetcode.com/problems/non-overlapping-intervals/description
// Description
// Given an array of intervals
// intervals
// where
// intervals[i] = [start
// i
// , end
// i
// ]
// , return
// the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping
// .
// Note
// that intervals which only touch at a point are
// non-overlapping
// . For example,
// [1, 2]
// and
// [2, 3]
// are non-overlapping.
// Example 1:
// Input:
// intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output:
// 1
// Explanation:
// [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:
// Input:
// intervals = [[1,2],[1,2],[1,2]]
// Output:
// 2
// Explanation:
// You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:
// Input:
// intervals = [[1,2],[2,3]]
// Output:
// 0
// Explanation:
// You don't need to remove any of the intervals since they're already non-overlapping.
// Constraints:
// 1 <= intervals.length <= 10
// 5
// intervals[i].length == 2
// -5 * 10
// 4
// <= start
// i
// < end
// i
// <= 5 * 10
// 4

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int n = intervals.size(), prev = intervals[0][1], ret = 0;
        for(int i = 1; i < n; i++){
            if(prev > intervals[i][0]){
                ret++;
                prev = min(prev, intervals[i][1]);
            }
            else{
                prev = intervals[i][1];
            }
        }
        return ret;
    }
};


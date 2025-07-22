// Link: https://leetcode.com/problems/minimum-time-difference/description
// Description
// Given a list of 24-hour clock time points in
// "HH:MM"
// format, return
// the minimum
// minutes
// difference between any two time-points in the list
// .
// Example 1:
// Input:
// timePoints = ["23:59","00:00"]
// Output:
// 1
// Example 2:
// Input:
// timePoints = ["00:00","23:59","00:00"]
// Output:
// 0
// Constraints:
// 2 <= timePoints.length <= 2 * 10
// 4
// timePoints[i]
// is in the format
// "HH:MM"
// .

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int ret = INT_MAX;
        vector<int> mins;
        for(const auto& t : timePoints){
            int hour = stoi(t.substr(0, 2));
            int min = stoi(t.substr(3, 5));
            mins.push_back(hour * 60 + min);
        }
        sort(mins.begin(), mins.end());
        int n = mins.size();
        // 1440 minutes is 24 hours
        ret = min(ret, 1440 + mins[0] - mins.back());
        for(int i = 1; i < n; i++){
            ret = min(ret, mins[i] - mins[i-1]);
        }
        return ret;
    }
};

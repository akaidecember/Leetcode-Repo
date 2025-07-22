// Link: https://leetcode.com/problems/count-days-without-meetings/description
// Description
// You are given a positive integer
// days
// representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array
// meetings
// of size
// n
// where,
// meetings[i] = [start_i, end_i]
// represents the starting and ending days of meeting
// i
// (inclusive).
// Return the count of days when the employee is available for work but no meetings are scheduled.
// Note:
// The meetings may overlap.
// Example 1:
// Input:
// days = 10, meetings = [[5,7],[1,3],[9,10]]
// Output:
// 2
// Explanation:
// There is no meeting scheduled on the 4
// th
// and 8
// th
// days.
// Example 2:
// Input:
// days = 5, meetings = [[2,4],[1,3]]
// Output:
// 1
// Explanation:
// There is no meeting scheduled on the 5
// th
// day.
// Example 3:
// Input:
// days = 6, meetings = [[1,6]]
// Output:
// 0
// Explanation:
// Meetings are scheduled for all working days.
// Constraints:
// 1 <= days <= 10
// 9
// 1 <= meetings.length <= 10
// 5
// meetings[i].length == 2
// 1 <= meetings[i][0] <= meetings[i][1] <= days

class Solution {
public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());

        int meetingDaysCount = 0;
        int currentStart = -1, currentEnd = -1;

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if (start > currentEnd) {
                if (currentEnd != -1) {
                    meetingDaysCount += currentEnd - currentStart + 1;
                }
                currentStart = start;
                currentEnd = end;
            } else {
                currentEnd = std::max(currentEnd, end);
            }
        }

        if (currentEnd != -1) {
            meetingDaysCount += currentEnd - currentStart + 1;
        }

        return days - meetingDaysCount;
    }
};

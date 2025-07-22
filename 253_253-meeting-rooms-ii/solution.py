# Link: https://leetcode.com/problems/meeting-rooms-ii/description
# Description
# Given an array of meeting time intervals
# intervals
# where
# intervals[i] = [start
# i
# , end
# i
# ]
# , return
# the minimum number of conference rooms required
# .
# Example 1:
# Input:
# intervals = [[0,30],[5,10],[15,20]]
# Output:
# 2
# Example 2:
# Input:
# intervals = [[7,10],[2,4]]
# Output:
# 1
# Constraints:
# 1 <= intervals.length <= 10
# 4
# 0 <= start
# i
# < end
# i
# <= 10
# 6

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[0])

        hp = []
        ans = 0
        for start, end in intervals:
            while hp and hp[0] <= start:
                heapq.heappop(hp)
            
            heapq.heappush(hp, end)
            ans = max(ans, len(hp))

        return ans




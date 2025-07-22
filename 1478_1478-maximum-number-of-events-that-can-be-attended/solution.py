# Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description
# Description
# You are given an array of
# events
# where
# events[i] = [startDay
# i
# , endDay
# i
# ]
# . Every event
# i
# starts at
# startDay
# i
# and ends at
# endDay
# i
# .
# You can attend an event
# i
# at any day
# d
# where
# startDay
# i
# <= d <= endDay
# i
# . You can only attend one event at any time
# d
# .
# Return
# the maximum number of events you can attend
# .
# Example 1:
# Input:
# events = [[1,2],[2,3],[3,4]]
# Output:
# 3
# Explanation:
# You can attend all the three events.
# One way to attend them all is as shown.
# Attend the first event on day 1.
# Attend the second event on day 2.
# Attend the third event on day 3.
# Example 2:
# Input:
# events= [[1,2],[2,3],[3,4],[1,2]]
# Output:
# 4
# Constraints:
# 1 <= events.length <= 10
# 5
# events[i].length == 2
# 1 <= startDay
# i
# <= endDay
# i
# <= 10
# 5

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        
        m = 0
        for eve in events:
            m = max(m,eve[1])
        
        events.sort(key = lambda x:(x[0],x[1]))
        heap = []
        res = 0
        event_ind = 0
        
        n = len(events)
        for day in range(1,m+1):
            # Pushing all the events in heap that starts Today
            while event_ind<n and events[event_ind][0]==day:
                heapq.heappush(heap,events[event_ind][1])
                event_ind += 1
            
            # Poping all the events in heap that ends Today
            while heap and heap[0]<day:
                heapq.heappop(heap)
            
            # If any event is there which can be attended today then pop it and add it to res count.
            if heap:
                heapq.heappop(heap)
                res+=1
        
        return res

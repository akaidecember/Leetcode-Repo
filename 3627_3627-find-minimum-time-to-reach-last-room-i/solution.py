# Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description
# Description
# There is a dungeon with
# n x m
# rooms arranged as a grid.
# You are given a 2D array
# moveTime
# of size
# n x m
# , where
# moveTime[i][j]
# represents the
# minimum
# time in seconds
# after
# which the room opens and can be moved to. You start from the room
# (0, 0)
# at time
# t = 0
# and can move to an
# adjacent
# room. Moving between adjacent rooms takes
# exactly
# one second.
# Return the
# minimum
# time to reach the room
# (n - 1, m - 1)
# .
# Two rooms are
# adjacent
# if they share a common wall, either
# horizontally
# or
# vertically
# .
# Example 1:
# Input:
# moveTime = [[0,4],[4,4]]
# Output:
# 6
# Explanation:
# The minimum time required is 6 seconds.
# At time
# t == 4
# , move from room
# (0, 0)
# to room
# (1, 0)
# in one second.
# At time
# t == 5
# , move from room
# (1, 0)
# to room
# (1, 1)
# in one second.
# Example 2:
# Input:
# moveTime = [[0,0,0],[0,0,0]]
# Output:
# 3
# Explanation:
# The minimum time required is 3 seconds.
# At time
# t == 0
# , move from room
# (0, 0)
# to room
# (1, 0)
# in one second.
# At time
# t == 1
# , move from room
# (1, 0)
# to room
# (1, 1)
# in one second.
# At time
# t == 2
# , move from room
# (1, 1)
# to room
# (1, 2)
# in one second.
# Example 3:
# Input:
# moveTime = [[0,1],[1,2]]
# Output:
# 3
# Constraints:
# 2 <= n == moveTime.length <= 50
# 2 <= m == moveTime[i].length <= 50
# 0 <= moveTime[i][j] <= 10
# 9

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n,m = len(moveTime), len(moveTime[0])
        heap = [(0,0,0)]
        visited = [[float('inf')] * m for _ in range(n)]
        visited[0][0] = 0

        dirs = [(1,0),(-1,0),(0,1),(0,-1)]

        while heap:
            time,r,c = heapq.heappop(heap)
            if time > visited[r][c]:
                continue
            if (r,c) == (n-1, m-1):
                return time
            
            for dr,dc in dirs:
                nr = r + dr
                nc = c + dc 
                if 0 <= nr < n and 0 <= nc < m:
                    temp = max(time + 1, moveTime[nr][nc] + 1)
                    if temp < visited[nr][nc]:
                        visited[nr][nc] = temp
                        heapq.heappush(heap, (temp,nr,nc))
                    
        return -1

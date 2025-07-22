# Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description
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
# time in seconds when you can
# start moving
# to that room. You start from the room
# (0, 0)
# at time
# t = 0
# and can move to an
# adjacent
# room. Moving between
# adjacent
# rooms takes one second for one move and two seconds for the next,
# alternating
# between the two.
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
# 7
# Explanation:
# The minimum time required is 7 seconds.
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
# in two seconds.
# Example 2:
# Input:
# moveTime = [[0,0,0,0],[0,0,0,0]]
# Output:
# 6
# Explanation:
# The minimum time required is 6 seconds.
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
# in two seconds.
# At time
# t == 3
# , move from room
# (1, 1)
# to room
# (1, 2)
# in one second.
# At time
# t == 4
# , move from room
# (1, 2)
# to room
# (1, 3)
# in two seconds.
# Example 3:
# Input:
# moveTime = [[0,1],[1,2]]
# Output:
# 4
# Constraints:
# 2 <= n == moveTime.length <= 750
# 2 <= m == moveTime[i].length <= 750
# 0 <= moveTime[i][j] <= 10
# 9

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n,m = len(moveTime), len(moveTime[0])
        heap = [(0,0,0,0)]
        visited = [[[float('inf')] * 2 for _ in range(m)] for _ in range(n)]
        visited[0][0][0] = 0

        dirs = [(1,0),(-1,0),(0,1),(0,-1)]

        while heap:
            time,r,c,p = heapq.heappop(heap)
            if time > visited[r][c][p]:
                continue
            if (r,c) == (n-1, m-1):
                return time
            
            for dr,dc in dirs:
                nr = r + dr
                nc = c + dc 
                if 0 <= nr < n and 0 <= nc < m:
                    cost = 1 if p == 0 else 2
                    temp = max(time + cost, moveTime[nr][nc] + cost)
                    np = 1 - p
                    if temp < visited[nr][nc][np]:
                        visited[nr][nc][np] = temp
                        heapq.heappush(heap, (temp,nr,nc,np))
                    
        return -1

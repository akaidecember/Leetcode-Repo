# Link: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description
# Description
# There is a
# directed graph
# of
# n
# colored nodes and
# m
# edges. The nodes are numbered from
# 0
# to
# n - 1
# .
# You are given a string
# colors
# where
# colors[i]
# is a lowercase English letter representing the
# color
# of the
# i
# th
# node in this graph (
# 0-indexed
# ). You are also given a 2D array
# edges
# where
# edges[j] = [a
# j
# , b
# j
# ]
# indicates that there is a
# directed edge
# from node
# a
# j
# to node
# b
# j
# .
# A valid
# path
# in the graph is a sequence of nodes
# x
# 1
# -> x
# 2
# -> x
# 3
# -> ... -> x
# k
# such that there is a directed edge from
# x
# i
# to
# x
# i+1
# for every
# 1 <= i < k
# . The
# color value
# of the path is the number of nodes that are colored the
# most frequently
# occurring color along that path.
# Return
# the
# largest color value
# of any valid path in the given graph, or
# -1
# if the graph contains a cycle
# .
# Example 1:
# Input:
# colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
# Output:
# 3
# Explanation:
# The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored
# "a" (red in the above image)
# .
# Example 2:
# Input:
# colors = "a", edges = [[0,0]]
# Output:
# -1
# Explanation:
# There is a cycle from 0 to 0.
# Constraints:
# n == colors.length
# m == edges.length
# 1 <= n <= 10
# 5
# 0 <= m <= 10
# 5
# colors
# consists of lowercase English letters.
# 0 <= a
# j
# , b
# j
# < n

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        # First you build a graph using the edges
        n = len(colors)
        graph = defaultdict(list)

        # Also store the in-degree of each node
        indeg = [0] * n

        for u, v in edges:
            graph[u].append(v)
            indeg[v] += 1

        q = deque()

        # Since the no. of nodes is equal to color len, we can use it to determine 
        # and add node index to q
        for i in range(n):
            if indeg[i] == 0:
                q.append(i)

        dp = [[0] * 26 for _ in range(n)]
        vis, maxCol = 0,0

        # 
        while q:
            # Popping from the left as we want to process the first node with 0 indeg.
            node = q.popleft()
            vis += 1

            colIdx = ord(colors[node]) - ord('a')
            # For the node, the respective color was encountered this many times
            dp[node][colIdx] += 1
            # Storing the max. ord color val count found till now
            maxCol = max(maxCol, dp[node][colIdx])

            # For each nei. in the graph...
            for nei in graph[node]:
                # And for every color...
                for c in range(26):
                    # Determine if the higher count lies with neighbor or current node
                    dp[nei][c] = max(dp[nei][c], dp[node][c])
                # Since the previous node is processed, we move on to the next set of nodes
                # comming right after the first 0 in-degree nodes.
                indeg[nei] -= 1
                # If the indeg is zero, then add them to q to process
                if indeg[nei] == 0:
                    q.append(nei)
        # If all nodes have been visited, then return ans, else there is a cycle.
        return maxCol if vis == n else -1

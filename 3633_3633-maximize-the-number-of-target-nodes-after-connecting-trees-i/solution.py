# Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description
# Description
# There exist two
# undirected
# trees with
# n
# and
# m
# nodes, with
# distinct
# labels in ranges
# [0, n - 1]
# and
# [0, m - 1]
# , respectively.
# You are given two 2D integer arrays
# edges1
# and
# edges2
# of lengths
# n - 1
# and
# m - 1
# , respectively, where
# edges1[i] = [a
# i
# , b
# i
# ]
# indicates that there is an edge between nodes
# a
# i
# and
# b
# i
# in the first tree and
# edges2[i] = [u
# i
# , v
# i
# ]
# indicates that there is an edge between nodes
# u
# i
# and
# v
# i
# in the second tree. You are also given an integer
# k
# .
# Node
# u
# is
# target
# to node
# v
# if the number of edges on the path from
# u
# to
# v
# is less than or equal to
# k
# .
# Note
# that a node is
# always
# target
# to itself.
# Return an array of
# n
# integers
# answer
# , where
# answer[i]
# is the
# maximum
# possible number of nodes
# target
# to node
# i
# of the first tree if you have to connect one node from the first tree to another node in the second tree.
# Note
# that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
# Example 1:
# Input:
# edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2
# Output:
# [9,7,9,8,8]
# Explanation:
# For
# i = 0
# , connect node 0 from the first tree to node 0 from the second tree.
# For
# i = 1
# , connect node 1 from the first tree to node 0 from the second tree.
# For
# i = 2
# , connect node 2 from the first tree to node 4 from the second tree.
# For
# i = 3
# , connect node 3 from the first tree to node 4 from the second tree.
# For
# i = 4
# , connect node 4 from the first tree to node 4 from the second tree.
# Example 2:
# Input:
# edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1
# Output:
# [6,3,3,3,3]
# Explanation:
# For every
# i
# , connect node
# i
# of the first tree with any node of the second tree.
# Constraints:
# 2 <= n, m <= 1000
# edges1.length == n - 1
# edges2.length == m - 1
# edges1[i].length == edges2[i].length == 2
# edges1[i] = [a
# i
# , b
# i
# ]
# 0 <= a
# i
# , b
# i
# < n
# edges2[i] = [u
# i
# , v
# i
# ]
# 0 <= u
# i
# , v
# i
# < m
# The input is generated such that
# edges1
# and
# edges2
# represent valid trees.
# 0 <= k <= 1000

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        n, m = len(edges1) + 1, len(edges2) + 1

        def build(edges):
            graph = defaultdict(list)
            for u, v in edges:
                graph[u].append(v)
                graph[v].append(u)
            return graph
        
        g1 = build(edges1)
        g2 = build(edges2)

        def countKDist(graph, n, k):
            counts = [0] * n
            for i in range(n):
                count = 0
                q = deque([(i, 0)])
                visited = [False] * n
                visited[i] = True
                while q:
                    node, dist = q.popleft()
                    if dist > k:
                        continue
                    count += 1
                    for neighbor in graph[node]:
                        if visited[neighbor] == False:
                            visited[neighbor] = True
                            q.append((neighbor, dist + 1))
                counts[i] = count
            return counts

        c1 = countKDist(g1, n, k)
        c2 = countKDist(g2, m, k-1)
        max_c2 = max(c2)

        return [i + max_c2 for i in c1]

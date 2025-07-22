# Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description
# Description
# There exist two
# undirected
# trees with
# n
# and
# m
# nodes, labeled from
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
# in the second tree.
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
# is even.
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
# possible number of nodes that are
# target
# to node
# i
# of the first tree if you had to connect one node from the first tree to another node in the second tree.
# Note
# that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
# Example 1:
# Input:
# edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
# Output:
# [8,7,7,8,8]
# Explanation:
# For
# i = 0
# , connect node 0 from the first tree to node 0 from the second tree.
# For
# i = 1
# , connect node 1 from the first tree to node 4 from the second tree.
# For
# i = 2
# , connect node 2 from the first tree to node 7 from the second tree.
# For
# i = 3
# , connect node 3 from the first tree to node 0 from the second tree.
# For
# i = 4
# , connect node 4 from the first tree to node 4 from the second tree.
# Example 2:
# Input:
# edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]
# Output:
# [3,6,6,6,6]
# Explanation:
# For every
# i
# , connect node
# i
# of the first tree with any node of the second tree.
# Constraints:
# 2 <= n, m <= 10
# 5
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

from typing import List

class Solution:
    def dfs(self, node: int, color: int, graph: List[List[int]],
            component: List[int], bipartite: List[int]) -> None:
        bipartite[color] += 1
        component[node] = color
        for neighbor in graph[node]:
            if component[neighbor] == -1:
                self.dfs(neighbor, 1 - color, graph, component, bipartite)

    def build_graph(self, edges: List[List[int]], n: int) -> List[List[int]]:
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        return graph

    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        n1, n2 = len(edges1) + 1, len(edges2) + 1


        graph1 = self.build_graph(edges1, n1)
        graph2 = self.build_graph(edges2, n2)

 
        component1 = [-1] * n1
        bipartite1 = [0, 0]
        self.dfs(0, 0, graph1, component1, bipartite1)


        ans = [bipartite1[component1[i]] for i in range(n1)]


        component2 = [-1] * n2
        bipartite2 = [0, 0]
        self.dfs(0, 0, graph2, component2, bipartite2)

        max_bipartite2 = max(bipartite2)
        return [val + max_bipartite2 for val in ans]

# Link: https://leetcode.com/problems/network-delay-time/description
# Description
# You are given a network of
# n
# nodes, labeled from
# 1
# to
# n
# . You are also given
# times
# , a list of travel times as directed edges
# times[i] = (u
# i
# , v
# i
# , w
# i
# )
# , where
# u
# i
# is the source node,
# v
# i
# is the target node, and
# w
# i
# is the time it takes for a signal to travel from source to target.
# We will send a signal from a given node
# k
# . Return
# the
# minimum
# time it takes for all the
# n
# nodes to receive the signal
# . If it is impossible for all the
# n
# nodes to receive the signal, return
# -1
# .
# Example 1:
# Input:
# times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
# Output:
# 2
# Example 2:
# Input:
# times = [[1,2,1]], n = 2, k = 1
# Output:
# 1
# Example 3:
# Input:
# times = [[1,2,1]], n = 2, k = 2
# Output:
# -1
# Constraints:
# 1 <= k <= n <= 100
# 1 <= times.length <= 6000
# times[i].length == 3
# 1 <= u
# i
# , v
# i
# <= n
# u
# i
# != v
# i
# 0 <= w
# i
# <= 100
# All the pairs
# (u
# i
# , v
# i
# )
# are
# unique
# . (i.e., no multiple edges.)

from typing import List
from collections import defaultdict
import heapq
import math

class FastSSSP:
    def __init__(self, graph, k=None, t=None):
        self.graph = graph
        self.n = len(graph)
        self.m = sum(len(adj) for adj in graph.values())
        self.k = k if k else math.ceil(math.log(self.n, 3))  # log^1/3(n)
        self.t = t if t else math.ceil(math.log(self.n, 1.5))  # log^2/3(n)
        self.dist = {v: float('inf') for v in graph}
        self.pred = {}
        self.complete = set()

    def relax(self, u, v, weight):
        if self.dist[u] + weight < self.dist[v]:
            self.dist[v] = self.dist[u] + weight
            self.pred[v] = u
            return True
        return False

    def base_case(self, source, B):
        visited = set()
        heap = [(self.dist[source], source)]
        u_set = set()

        while heap and len(u_set) < self.k + 1:
            d_u, u = heapq.heappop(heap)
            if u in visited or d_u >= B:
                continue
            visited.add(u)
            u_set.add(u)
            self.complete.add(u)
            for v, weight in self.graph[u]:
                if self.relax(u, v, weight):
                    heapq.heappush(heap, (self.dist[v], v))

        if len(u_set) <= self.k:
            return B, u_set
        else:
            new_B = max(self.dist[v] for v in u_set)
            trimmed_u = {v for v in u_set if self.dist[v] < new_B}
            return new_B, trimmed_u

    def find_pivots(self, S, B):
        W = set(S)
        W_prev = set(S)
        for _ in range(self.k):
            W_next = set()
            for u in W_prev:
                for v, weight in self.graph[u]:
                    if self.dist[u] + weight < self.dist[v] and self.dist[u] + weight < B:
                        self.dist[v] = self.dist[u] + weight
                        self.pred[v] = u
                        W_next.add(v)
            if not W_next:
                break
            W |= W_next
            W_prev = W_next

        if len(W) > self.k * len(S):
            return S, W

        subtree_sizes = defaultdict(int)
        for v in W:
            u = self.pred.get(v)
            if u in S:
                subtree_sizes[u] += 1

        P = {u for u, size in subtree_sizes.items() if size >= self.k}
        return list(P), W

    def bmssp(self, l, B, S):
        if l == 0:
            return self.base_case(S[0], B)

        P, W = self.find_pivots(S, B)
        U = set()
        Q = [(self.dist[x], x) for x in P]
        heapq.heapify(Q)

        while Q and len(U) < self.k * (2 ** (l * self.t)):
            _, x = heapq.heappop(Q)
            B_i = self.dist[x]
            _, U_i = self.bmssp(l - 1, B_i + 1e-5, [x])
            U |= U_i

            for u in U_i:
                for v, weight in self.graph[u]:
                    if self.relax(u, v, weight):
                        heapq.heappush(Q, (self.dist[v], v))

        max_dist = max((self.dist[v] for v in U), default=0)
        final_U = U | {v for v in W if self.dist[v] < max_dist}
        self.complete |= final_U
        return max_dist, final_U

    def run(self, source):
        self.dist[source] = 0
        l = math.ceil(math.log(self.n) / self.t)
        B = float('inf')
        
        visited = set()
        changed = True

        while changed:
            changed = False
            current_sources = [v for v in self.dist if self.dist[v] < float('inf') and v not in self.complete]
            for v in current_sources:
                _, completed = self.bmssp(l, B, [v])
                if completed - visited:
                    changed = True
                visited |= completed

        return self.dist


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        def convert_to_graph(times, n):
            graph = defaultdict(list)
            for u, v, w in times:
                graph[u].append((v, w))
            for i in range(1, n + 1):
                if i not in graph:
                    graph[i] = []
            return graph

        graph = convert_to_graph(times, n)
        fast_sssp_solver = FastSSSP(graph)
        distances = fast_sssp_solver.run(k)
        max_dist = max(distances.values())
        return max_dist if max_dist < float('inf') else -1


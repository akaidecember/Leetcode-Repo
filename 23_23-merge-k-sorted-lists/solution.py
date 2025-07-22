# Link: https://leetcode.com/problems/merge-k-sorted-lists/description
# Description
# You are given an array of
# k
# linked-lists
# lists
# , each linked-list is sorted in ascending order.
# Merge all the linked-lists into one sorted linked-list and return it.
# Example 1:
# Input:
# lists = [[1,4,5],[1,3,4],[2,6]]
# Output:
# [1,1,2,3,4,4,5,6]
# Explanation:
# The linked-lists are:
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# merging them into one sorted linked list:
# 1->1->2->3->4->4->5->6
# Example 2:
# Input:
# lists = []
# Output:
# []
# Example 3:
# Input:
# lists = [[]]
# Output:
# []
# Constraints:
# k == lists.length
# 0 <= k <= 10
# 4
# 0 <= lists[i].length <= 500
# -10
# 4
# <= lists[i][j] <= 10
# 4
# lists[i]
# is sorted in
# ascending order
# .
# The sum of
# lists[i].length
# will not exceed
# 10
# 4
# .

class HeapNode:
    def __init__(self, node):
        self.node = node

    def __lt__(self, other):
        return self.node.val < other.node.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dummy = ListNode(0)
        current = dummy
        heap = []

        for l in lists:
            if l:
                heapq.heappush(heap, HeapNode(l))

        while heap:
            heap_node = heapq.heappop(heap)
            node = heap_node.node
            current.next = node
            current = current.next
            if node.next:
                heapq.heappush(heap, HeapNode(node.next))

        return dummy.next

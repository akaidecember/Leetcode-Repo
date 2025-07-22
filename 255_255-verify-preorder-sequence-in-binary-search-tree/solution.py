# Link: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/description
# Description
# Given an array of
# unique
# integers
# preorder
# , return
# true
# if it is the correct preorder traversal sequence of a binary search tree
# .
# Example 1:
# Input:
# preorder = [5,2,1,3,6]
# Output:
# true
# Example 2:
# Input:
# preorder = [5,2,6,1,3]
# Output:
# false
# Constraints:
# 1 <= preorder.length <= 10
# 4
# 1 <= preorder[i] <= 10
# 4
# All the elements of
# preorder
# are
# unique
# .
# Follow up:
# Could you do it using only constant space complexity?

class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        stk = []
        root = float('-inf')

        for val in preorder:
            if val < root:
                return False

            while stk and stk[-1] < val:
                root = stk.pop()

            stk.append(val)

        return True

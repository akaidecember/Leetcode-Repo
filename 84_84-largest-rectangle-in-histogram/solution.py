# Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description
# Description
# Given an array of integers
# heights
# representing the histogram's bar height where the width of each bar is
# 1
# , return
# the area of the largest rectangle in the histogram
# .
# Example 1:
# Input:
# heights = [2,1,5,6,2,3]
# Output:
# 10
# Explanation:
# The above is a histogram where width of each bar is 1.
# The largest rectangle is shown in the red area, which has an area = 10 units.
# Example 2:
# Input:
# heights = [2,4]
# Output:
# 4
# Constraints:
# 1 <= heights.length <= 10
# 5
# 0 <= heights[i] <= 10
# 4

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stk = [-1]
        ret, n = 0, len(heights)

        for i in range(n):
            while stk[-1] != -1 and heights[stk[-1]] >= heights[i]:
                currHeight = heights[stk.pop()]
                currWidth = i - stk[-1] - 1
                ret = max(ret, currHeight * currWidth)
            stk.append(i)

        while stk[-1] != -1:
            currHeight = heights[stk.pop()]
            currWidth = n - stk[-1] - 1
            ret = max(ret, currHeight * currWidth)

        return ret
        

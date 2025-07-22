# Link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description
# Description
# You have
# n
# boxes labeled from
# 0
# to
# n - 1
# . You are given four arrays:
# status
# ,
# candies
# ,
# keys
# , and
# containedBoxes
# where:
# status[i]
# is
# 1
# if the
# i
# th
# box is open and
# 0
# if the
# i
# th
# box is closed,
# candies[i]
# is the number of candies in the
# i
# th
# box,
# keys[i]
# is a list of the labels of the boxes you can open after opening the
# i
# th
# box.
# containedBoxes[i]
# is a list of the boxes you found inside the
# i
# th
# box.
# You are given an integer array
# initialBoxes
# that contains the labels of the boxes you initially have. You can take all the candies in
# any open box
# and you can use the keys in it to open new boxes and you also can use the boxes you find in it.
# Return
# the maximum number of candies you can get following the rules above
# .
# Example 1:
# Input:
# status = [1,0,1,0], candies = [7,5,4,100], keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], initialBoxes = [0]
# Output:
# 16
# Explanation:
# You will be initially given box 0. You will find 7 candies in it and boxes 1 and 2.
# Box 1 is closed and you do not have a key for it so you will open box 2. You will find 4 candies and a key to box 1 in box 2.
# In box 1, you will find 5 candies and box 3 but you will not find a key to box 3 so box 3 will remain closed.
# Total number of candies collected = 7 + 4 + 5 = 16 candy.
# Example 2:
# Input:
# status = [1,0,0,0,0,0], candies = [1,1,1,1,1,1], keys = [[1,2,3,4,5],[],[],[],[],[]], containedBoxes = [[1,2,3,4,5],[],[],[],[],[]], initialBoxes = [0]
# Output:
# 6
# Explanation:
# You have initially box 0. Opening it you can find boxes 1,2,3,4 and 5 and their keys.
# The total number of candies will be 6.
# Constraints:
# n == status.length == candies.length == keys.length == containedBoxes.length
# 1 <= n <= 1000
# status[i]
# is either
# 0
# or
# 1
# .
# 1 <= candies[i] <= 1000
# 0 <= keys[i].length <= n
# 0 <= keys[i][j] < n
# All values of
# keys[i]
# are
# unique
# .
# 0 <= containedBoxes[i].length <= n
# 0 <= containedBoxes[i][j] < n
# All values of
# containedBoxes[i]
# are unique.
# Each box is contained in one box at most.
# 0 <= initialBoxes.length <= n
# 0 <= initialBoxes[i] < n

class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        n = len(status)
        q = deque(initialBoxes)
        owned, keySt, opened = set(initialBoxes), set(), set()
        ret = 0

        while q:
            m = len(q)
            vis = False
            for _ in range(m):
                box = q.popleft()
                if status[box] or box in keySt:
                    if box in opened:
                        continue
                    opened.add(box)
                    ret += candies[box]

                    for key in keys[box]:
                        keySt.add(key)
                        if key in owned and key not in opened:
                            q.append(key)

                    for box in containedBoxes[box]:
                        if box not in owned:
                            owned.add(box)
                            q.append(box)
                        elif status[box] == 1 or box in keySt:
                            q.append(box)
                else:
                    q.append(box)

            openMore = any(status[box] == 1 or box in keySt for box in q if box not in opened)
            if not openMore:
                break

        return ret






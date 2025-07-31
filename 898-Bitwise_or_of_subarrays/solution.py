'''

Leetcode 898: Bitwise ORs of Subarrays
--------------------------------------

Given an integer array `arr`, return the number of distinct bitwise ORs of all the non-empty subarrays of `arr`.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. 
The bitwise OR of a subarray with one element is that element itself.

A subarray is a contiguous non-empty sequence of elements within an array.

---------------------------------------------------------
Examples
---------------------------------------------------------

Example 1:
Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.

Example 2:
Input: arr = [1, 1, 2]
Output: 3
Explanation: 
  The possible subarrays are: [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
  These yield the results:     1,    1,   2,     1,     3,        3.
  Unique values: 1, 2, 3 => total of 3 unique results.

Example 3:
Input: arr = [1, 2, 4]
Output: 6
Explanation:
  The possible OR results are: 1, 2, 3, 4, 6, 7.

---------------------------------------------------------
Constraints
---------------------------------------------------------
• 1 <= arr.length <= 50,000
• 0 <= arr[i] <= 1,000,000,000

https://leetcode.com/problems/bitwise-ors-of-subarrays/description/?envType=daily-question&envId=2025-07-31

'''

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        ret, one = set(arr), set()
        one.add(arr[0])

        n = len(arr)

        for i in range(1, n):
            two = set()
            for j in one:
                two.add(j | arr[i])
                ret.add(j | arr[i])
            two.add(arr[i])
            one = two

        return len(ret)


"""
    Given a 0-indexed array `nums` of non-negative integers, this function returns an array `answer` of the same length.
    For each index `i` (0 <= i < len(nums)), `answer[i]` represents the length of the smallest subarray starting at `i`
    such that the bitwise OR of the subarray is equal to the maximum bitwise OR obtainable from any subarray starting at `i`.

    The bitwise OR of a subarray is defined as the result of applying the bitwise OR operation on all its elements.

    Parameters:
    nums (List[int]): A list of non-negative integers (0 <= nums[i] <= 10^9)

    Returns:
    List[int]: An array where each element `answer[i]` is the minimum length of subarray starting at index `i` with maximum bitwise OR.

    Examples:
    >>> smallest_subarrays([1, 0, 2, 1, 3])
    [3, 3, 2, 2, 1]
    Explanation:
        - The maximum bitwise OR starting from any index is 3.
        - From index 0, [1, 0, 2] gives OR = 3 in 3 elements.
        - From index 1, [0, 2, 1] gives OR = 3 in 3 elements.
        - From index 2, [2, 1] gives OR = 3 in 2 elements.
        - From index 3, [1, 3] gives OR = 3 in 2 elements.
        - From index 4, [3] gives OR = 3 in 1 element.

    >>> smallest_subarrays([1, 2])
    [2, 1]
"""

class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ret = [0] * n

        for i in range(n):
            x = nums[i]
            ret[i] = 1
            j = i - 1

            while j >= 0 and nums[j] | x != nums[j]:
                ret[j] = i - j + 1
                nums[j] |= x
                j -= 1

        return ret

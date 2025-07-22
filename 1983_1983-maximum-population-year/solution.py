# Link: https://leetcode.com/problems/maximum-population-year/description
# Description
# You are given a 2D integer array
# logs
# where each
# logs[i] = [birth
# i
# , death
# i
# ]
# indicates the birth and death years of the
# i
# th
# person.
# The
# population
# of some year
# x
# is the number of people alive during that year. The
# i
# th
# person is counted in year
# x
# 's population if
# x
# is in the
# inclusive
# range
# [birth
# i
# , death
# i
# - 1]
# . Note that the person is
# not
# counted in the year that they die.
# Return
# the
# earliest
# year with the
# maximum population
# .
# Example 1:
# Input:
# logs = [[1993,1999],[2000,2010]]
# Output:
# 1993
# Explanation:
# The maximum population is 1, and 1993 is the earliest year with this population.
# Example 2:
# Input:
# logs = [[1950,1961],[1960,1971],[1970,1981]]
# Output:
# 1960
# Explanation:
# The maximum population is 2, and it had happened in years 1960 and 1970.
# The earlier year between them is 1960.
# Constraints:
# 1 <= logs.length <= 100
# 1950 <= birth
# i
# < death
# i
# <= 2050

class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        years = [0] * (2050 - 1950 + 1)

        for log in logs:
            years[log[0] - 1950] += 1
            years[log[1] - 1950] -= 1

        maxPopulation, current, ret = 0,0,1950

        for i in range(101):
            current += years[i]
            if current > maxPopulation:
                maxPopulation = current
                ret = 1950 + i

        return ret

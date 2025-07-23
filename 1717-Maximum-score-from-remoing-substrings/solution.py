'''
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
 

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.
'''

class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        ret, n = 0, len(s)

        if y > x:
            st = []
            visited = [False] * n

            for i in range(n):
                if st and st[-1][0] == 'b' and s[i] == 'a':
                    visited[i] = True
                    visited[st[-1][1]] = True
                    st.pop()
                    ret += y
                else:
                    st.append((s[i], i))

            st.clear()

            for i in range(n):
                if visited[i]:
                    continue
                if st and st[-1][0] == 'a' and s[i] == 'b':
                    st.pop()
                    ret += x
                else:
                    st.append((s[i], i))

        else:
            st = []
            visited = [False] * n

            for i in range(n):
                if st and st[-1][0] == 'a' and s[i] == 'b':
                    visited[i] = True
                    visited[st[-1][1]] = True
                    st.pop()
                    ret += x
                else:
                    st.append((s[i], i))

            st.clear()

            for i in range(n):
                if visited[i]:
                    continue
                if st and st[-1][0] == 'b' and s[i] == 'a':
                    st.pop()
                    ret += y
                else:
                    st.append((s[i], i))

        return ret

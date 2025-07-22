// Link: https://leetcode.com/problems/minimum-knight-moves/description
// Description
// In an
// infinite
// chess board with coordinates from
// -infinity
// to
// +infinity
// , you have a
// knight
// at square
// [0, 0]
// .
// A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
// Return
// the minimum number of steps needed to move the knight to the square
// [x, y]
// . It is guaranteed the answer exists.
// Example 1:
// Input:
// x = 2, y = 1
// Output:
// 1
// Explanation:
// [0, 0] → [2, 1]
// Example 2:
// Input:
// x = 5, y = 5
// Output:
// 4
// Explanation:
// [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
// Constraints:
// -300 <= x, y <= 300
// 0 <= |x| + |y| <= 300

class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator() (const pair<T1, T2>& p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2; 
        }
    };

    int dfs(int x, int y, unordered_map<pair<int, int>, int, pair_hash> &dp) {
        if (x > y) {
            swap(x, y);
        }
        if (dp.count({x, y})) {
            return dp[{x, y}];
        }
        dp[{x, y}] = min(dfs(abs(x - 2), abs(y - 1), dp), dfs(abs(x - 1), abs(y - 2), dp)) + 1;
        return dp[{x, y}];
    }

    int minKnightMoves(int x, int y) {
        unordered_map<pair<int, int>, int, pair_hash> dp = {
            {{0, 0}, 0},
            {{0, 1}, 3},
            {{1, 0}, 3},
            {{0, 2}, 2},
            {{2, 0}, 2},
            {{1, 1}, 2},
            {{1, 2}, 1},
            {{2, 1}, 1}
        };
        return dfs(abs(x), abs(y), dp);
    }
};

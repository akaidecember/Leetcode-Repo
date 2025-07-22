// Link: https://leetcode.com/problems/the-maze-ii/description
// Description
// There is a ball in a
// maze
// with empty spaces (represented as
// 0
// ) and walls (represented as
// 1
// ). The ball can go through the empty spaces by rolling
// up, down, left or right
// , but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
// Given the
// m x n
// maze
// , the ball's
// start
// position and the
// destination
// , where
// start = [start
// row
// , start
// col
// ]
// and
// destination = [destination
// row
// , destination
// col
// ]
// , return
// the shortest
// distance
// for the ball to stop at the destination
// . If the ball cannot stop at
// destination
// , return
// -1
// .
// The
// distance
// is the number of
// empty spaces
// traveled by the ball from the start position (excluded) to the destination (included).
// You may assume that
// the borders of the maze are all walls
// (see examples).
// Example 1:
// Input:
// maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
// Output:
// 12
// Explanation:
// One possible way is : left -> down -> left -> down -> right -> down -> right.
// The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
// Example 2:
// Input:
// maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
// Output:
// -1
// Explanation:
// There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
// Example 3:
// Input:
// maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
// Output:
// -1
// Constraints:
// m == maze.length
// n == maze[i].length
// 1 <= m, n <= 100
// maze[i][j]
// is
// 0
// or
// 1
// .
// start.length == 2
// destination.length == 2
// 0 <= start
// row
// , destination
// row
// < m
// 0 <= start
// col
// , destination
// col
// < n
// Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
// The maze contains
// at least 2 empty spaces
// .

class Solution {
private:
    array<array<int, 2>, 4> dirs = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};  

public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));  
        dist[start[0]][start[1]] = 0; 

        using T = tuple<int, int, int>;  
        priority_queue<T, vector<T>, greater<T>> pq;  
        pq.push({0, start[0], start[1]});

        while(!pq.empty()){
            auto [currentDist, r, c] = pq.top();
            pq.pop();

            if(currentDist > dist[r][c]){
                continue;
            }

            for (auto& [dx, dy] : dirs){
                int x = r, y = c, steps = 0;

                while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && maze[x + dx][y + dy] != 1){
                    x += dx;
                    y += dy;
                    steps++;
                }
                
                int newDist = currentDist + steps;

                if (newDist < dist[x][y]){
                    dist[x][y] = newDist;
                    pq.push({newDist, x, y});
                }
            }
        }

        return dist[destination[0]][destination[1]] == INT_MAX ? -1 : dist[destination[0]][destination[1]];
    }
};

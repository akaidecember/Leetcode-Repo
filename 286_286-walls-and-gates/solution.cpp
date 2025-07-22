// Link: https://leetcode.com/problems/walls-and-gates/description
// Description
// You are given an
// m x n
// grid
// rooms
// initialized with these three possible values.
// -1
// A wall or an obstacle.
// 0
// A gate.
// INF
// Infinity means an empty room. We use the value
// 2
// 31
// - 1 = 2147483647
// to represent
// INF
// as you may assume that the distance to a gate is less than
// 2147483647
// .
// Fill each empty room with the distance to
// its nearest gate
// . If it is impossible to reach a gate, it should be filled with
// INF
// .
// Example 1:
// Input:
// rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
// Output:
// [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
// Example 2:
// Input:
// rooms = [[-1]]
// Output:
// [[-1]]
// Constraints:
// m == rooms.length
// n == rooms[i].length
// 1 <= m, n <= 250
// rooms[i][j]
// is
// -1
// ,
// 0
// , or
// 2
// 31
// - 1
// .

class Solution {
private:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> gate_idx;

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int m = rooms.size(), n = rooms[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0){
                    gate_idx.emplace(i, j);
                }
            }
        }

        while(!gate_idx.empty()){
            auto temp = gate_idx.front();
            gate_idx.pop();

            int i = temp.first, j = temp.second;

            for(const auto& d : dirs){
                int x = i + d.first, y = j + d.second;

                if(x < 0 or y < 0 or x >= m or y >= n or rooms[x][y] < INT_MAX){
                    continue;
                }

                rooms[x][y] = rooms[i][j] + 1;
                gate_idx.emplace(x, y);
            }
        }
    }
};

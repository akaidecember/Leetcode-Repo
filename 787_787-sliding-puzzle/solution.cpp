// Link: https://leetcode.com/problems/sliding-puzzle/description
// Description
// On an
// 2 x 3
// board, there are five tiles labeled from
// 1
// to
// 5
// , and an empty square represented by
// 0
// . A
// move
// consists of choosing
// 0
// and a 4-directionally adjacent number and swapping it.
// The state of the board is solved if and only if the board is
// [[1,2,3],[4,5,0]]
// .
// Given the puzzle board
// board
// , return
// the least number of moves required so that the state of the board is solved
// . If it is impossible for the state of the board to be solved, return
// -1
// .
// Example 1:
// Input:
// board = [[1,2,3],[4,0,5]]
// Output:
// 1
// Explanation:
// Swap the 0 and the 5 in one move.
// Example 2:
// Input:
// board = [[1,2,3],[5,4,0]]
// Output:
// -1
// Explanation:
// No number of moves will make the board solved.
// Example 3:
// Input:
// board = [[4,1,2],[5,0,3]]
// Output:
// 5
// Explanation:
// 5 is the smallest number of moves that solves the board.
// An example path:
// After move 0: [[4,1,2],[5,0,3]]
// After move 1: [[4,1,2],[0,5,3]]
// After move 2: [[0,1,2],[4,5,3]]
// After move 3: [[1,0,2],[4,5,3]]
// After move 4: [[1,2,0],[4,5,3]]
// After move 5: [[1,2,3],[4,5,0]]
// Constraints:
// board.length == 2
// board[i].length == 3
// 0 <= board[i][j] <= 5
// Each value
// board[i][j]
// is
// unique
// .

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int rowSize = 2, colSize = 3;
        string compare = "", target = "123450";

        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                compare += to_string(board[i][j]);
            }
        }

        queue<pair<string, int>> q; 
        q.push({compare, 0});
        unordered_set<string> visited;
        visited.insert(compare);

        while(!q.empty()){
            auto[curr_state, steps] = q.front();
            q.pop();

            if(curr_state == target){
                return steps;
            }

            int zero_index = -1;

            for(int i = 0; i < curr_state.size(); i++){
                if(curr_state[i] == '0'){
                    zero_index = i;
                    break;
                }
            }
            
            if(zero_index == -1){
                break;
            }

            if(zero_index > 2){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index-3]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }

            if(zero_index < 3){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index+3]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }

            if(zero_index != 0 && zero_index != 3){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index-1]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }

            if(zero_index != 2 && zero_index != 5){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index+1]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }
        }

        return -1;
    }
};

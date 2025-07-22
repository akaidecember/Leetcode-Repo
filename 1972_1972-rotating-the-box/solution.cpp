// Link: https://leetcode.com/problems/rotating-the-box/description
// Description
// You are given an
// m x n
// matrix of characters
// boxGrid
// representing a side-view of a box. Each cell of the box is one of the following:
// A stone
// '#'
// A stationary obstacle
// '*'
// Empty
// '.'
// The box is rotated
// 90 degrees clockwise
// , causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity
// does not
// affect the obstacles' positions, and the inertia from the box's rotation
// does not
// affect the stones' horizontal positions.
// It is
// guaranteed
// that each stone in
// boxGrid
// rests on an obstacle, another stone, or the bottom of the box.
// Return
// an
// n x m
// matrix representing the box after the rotation described above
// .
// Example 1:
// Input:
// boxGrid = [["#",".","#"]]
// Output:
// [["."],
//          ["#"],
//          ["#"]]
// Example 2:
// Input:
// boxGrid = [["#",".","*","."],
//               ["#","#","*","."]]
// Output:
// [["#","."],
//          ["#","#"],
//          ["*","*"],
//          [".","."]]
// Example 3:
// Input:
// boxGrid = [["#","#","*",".","*","."],
//               ["#","#","#","*",".","."],
//               ["#","#","#",".","#","."]]
// Output:
// [[".","#","#"],
//          [".","#","#"],
//          ["#","#","*"],
//          ["#","*","."],
//          ["#",".","*"],
//          ["#",".","."]]
// Constraints:
// m == boxGrid.length
// n == boxGrid[i].length
// 1 <= m, n <= 500
// boxGrid[i][j]
// is either
// '#'
// ,
// '*'
// , or
// '.'
// .

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();

        for (int row = 0; row < rows; ++row) {
            int empty = cols - 1; 

            for (int col = cols - 1; col >= 0; --col) {
                if (box[row][col] == '#') {
                    swap(box[row][col], box[row][empty--]);
                } else if (box[row][col] == '*') {
                    empty = col - 1; 
                }
            }
        }

        vector<vector<char>> rotatedBox(cols, vector<char>(rows, '.'));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                rotatedBox[col][rows - row - 1] = box[row][col];
            }
        }

        return rotatedBox;
    }
};


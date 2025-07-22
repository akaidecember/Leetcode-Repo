// Link: https://leetcode.com/problems/word-search/description
// Description
// Given an
// m x n
// grid of characters
// board
// and a string
// word
// , return
// true
// if
// word
// exists in the grid
// .
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
// Example 1:
// Input:
// board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output:
// true
// Example 2:
// Input:
// board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output:
// true
// Example 3:
// Input:
// board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output:
// false
// Constraints:
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board
// and
// word
// consists of only lowercase and uppercase English letters.
// Follow up:
// Could you use search pruning to make your solution faster with a larger
// board
// ?

class Solution {
public:
    bool solver(vector<vector<char>>& board, string word, int i, int j, int idx){
        if(idx == word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]){
            return false;
        }
        board[i][j] = '*';
        // Up
        if(solver(board, word, i - 1, j, idx + 1)){
            return true;
        }
        // Down
        if(solver(board, word, i + 1, j, idx + 1)){
            return true;
        }
        // Left
        if(solver(board, word, i, j - 1, idx + 1)){
            return true;
        }
        // Right
        if(solver(board, word, i, j + 1, idx + 1)){
            return true;
        }
        board[i][j] = word[idx];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        if(word.size() > m * n){
            return false;
        }
        if(count(word.begin(), word.end(), word[0]) > count(word.begin(), word.end(), word[word.size()-1])){
            reverse(word.begin(), word.end());
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(solver(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

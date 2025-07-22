// Link: https://leetcode.com/problems/n-queens/description
// Description
// The
// n-queens
// puzzle is the problem of placing
// n
// queens on an
// n x n
// chessboard such that no two queens attack each other.
// Given an integer
// n
// , return
// all distinct solutions to the
// n-queens puzzle
// . You may return the answer in
// any order
// .
// Each solution contains a distinct board configuration of the n-queens' placement, where
// 'Q'
// and
// '.'
// both indicate a queen and an empty space, respectively.
// Example 1:
// Input:
// n = 4
// Output:
// [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation:
// There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:
// Input:
// n = 1
// Output:
// [["Q"]]
// Constraints:
// 1 <= n <= 9

class Solution {
public:
    void helper(int i, int j, int ld, int rd, vector<vector<string>> &ret, vector<string> &bd){
        int n = bd.size();
        if(i == n){
            vector<string> temp;
            for(auto row : bd)
                temp.push_back(row);
            ret.push_back(temp);
            return;
        }
        for(int ctr = 0; ctr <n; ctr++){
            int vmask = 1 << ctr, lmask = 1 << (i+ctr), rmask = 1 << (n-i-1+ctr);
            if(j & vmask || ld & lmask || rd & rmask)
                continue;
            bd[i][ctr] = 'Q';
            helper(i+1, j | vmask, ld | lmask, rd | rmask, ret, bd);
            bd[i][ctr] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> bd;
        bd.resize(n, string(n,'.'));
        helper(0,0,0,0, ret, bd);
        return ret;
    }
};

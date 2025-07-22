// Link: https://leetcode.com/problems/maximal-rectangle/description
// Description
// Given a
// rows x cols
// binary
// matrix
// filled with
// 0
// 's and
// 1
// 's, find the largest rectangle containing only
// 1
// 's and return
// its area
// .
// Example 1:
// Input:
// matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output:
// 6
// Explanation:
// The maximal rectangle is shown in the above picture.
// Example 2:
// Input:
// matrix = [["0"]]
// Output:
// 0
// Example 3:
// Input:
// matrix = [["1"]]
// Output:
// 1
// Constraints:
// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j]
// is
// '0'
// or
// '1'
// .

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int ret = 0, n = matrix.size(), m = matrix[0].size();;
        vector<int> v, temp(m, 0);
        v.push_back(-1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0'){
                    temp[j] = 0;
                }
                else{
                    temp[j]++;
                }
            }
            for(int k = 0; k < m; k++){
                while(v.back() != -1 && temp[v.back()] >= temp[k]){
                    int curr_h = temp[v.back()];
                    v.pop_back();
                    int curr_w = k - v.back() - 1;
                    ret = max(ret, curr_h * curr_w);
                }
                v.push_back(k);
            }
            while(v.back() != -1){
                int curr_h = temp[v.back()];
                v.pop_back();
                int curr_w = m - v.back() - 1;
                ret = max(ret, curr_h * curr_w);
            }
        }
        return ret;
    }
};

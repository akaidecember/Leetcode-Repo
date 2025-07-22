// Link: https://leetcode.com/problems/build-a-matrix-with-conditions/description
// Description
// You are given a
// positive
// integer
// k
// . You are also given:
// a 2D integer array
// rowConditions
// of size
// n
// where
// rowConditions[i] = [above
// i
// , below
// i
// ]
// , and
// a 2D integer array
// colConditions
// of size
// m
// where
// colConditions[i] = [left
// i
// , right
// i
// ]
// .
// The two arrays contain integers from
// 1
// to
// k
// .
// You have to build a
// k x k
// matrix that contains each of the numbers from
// 1
// to
// k
// exactly once
// . The remaining cells should have the value
// 0
// .
// The matrix should also satisfy the following conditions:
// The number
// above
// i
// should appear in a
// row
// that is strictly
// above
// the row at which the number
// below
// i
// appears for all
// i
// from
// 0
// to
// n - 1
// .
// The number
// left
// i
// should appear in a
// column
// that is strictly
// left
// of the column at which the number
// right
// i
// appears for all
// i
// from
// 0
// to
// m - 1
// .
// Return
// any
// matrix that satisfies the conditions
// . If no answer exists, return an empty matrix.
// Example 1:
// Input:
// k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
// Output:
// [[3,0,0],[0,0,1],[0,2,0]]
// Explanation:
// The diagram above shows a valid example of a matrix that satisfies all the conditions.
// The row conditions are the following:
// - Number 1 is in row
// 1
// , and number 2 is in row
// 2
// , so 1 is above 2 in the matrix.
// - Number 3 is in row
// 0
// , and number 2 is in row
// 2
// , so 3 is above 2 in the matrix.
// The column conditions are the following:
// - Number 2 is in column
// 1
// , and number 1 is in column
// 2
// , so 2 is left of 1 in the matrix.
// - Number 3 is in column
// 0
// , and number 2 is in column
// 1
// , so 3 is left of 2 in the matrix.
// Note that there may be multiple correct answers.
// Example 2:
// Input:
// k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
// Output:
// []
// Explanation:
// From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
// No matrix can satisfy all the conditions, so we return the empty matrix.
// Constraints:
// 2 <= k <= 400
// 1 <= rowConditions.length, colConditions.length <= 10
// 4
// rowConditions[i].length == colConditions[i].length == 2
// 1 <= above
// i
// , below
// i
// , left
// i
// , right
// i
// <= k
// above
// i
// != below
// i
// left
// i
// != right
// i

class Solution {
public:
    bool dfs(int src, map<int, vector<int>> &adj, 
                set<int> &vis, set<int> &path, vector<int> &ret){
        if(path.find(src) != path.end()) return false;
        if(vis.find(src) != vis.end()) return true;
        vis.insert(src);
        path.insert(src);
        for(auto n : adj[src]){
            if(!dfs(n, adj, vis, path, ret)) return false;
        }
        path.erase(src);
        ret.insert(ret.begin(), src);
        return true;
    }

    vector<int> topsort(vector<vector<int>> &conditions, int k){
        map<int, vector<int>> adj;
        vector<int> ret;
        set<int> vis, path;
        for(const auto& c : conditions){
            adj[c[0]].push_back(c[1]);
        }
        for(int i = 1; i < k+1; i++){
            if(!dfs(i, adj, vis, path, ret)) return {};
        }
        //reverse(ret.begin(), ret.end());
        return ret;
    }

    vector<vector<int>> buildMatrix(int k,
                         vector<vector<int>>& rowConditions,                        
                         vector<vector<int>>& colConditions) {
                            
        vector<int> row, col;
        row = topsort(rowConditions, k);
        col = topsort(colConditions, k);
        if(row.empty() || col.empty()){
            return {};
        }
        vector<vector<int>> ret(k, vector<int>(k, 0));
        map<int,int> row_val, col_val;
        int rs = row.size(), cs = col.size();
        for(int i = 0; i < rs; i++) row_val[row[i]] = i;
        for(int i = 0; i < cs; i++) col_val[col[i]] = i;
        for(int i = 1; i < k+1; i++){
            ret[row_val[i]][col_val[i]] = i;
        }
        return ret;
    }
};

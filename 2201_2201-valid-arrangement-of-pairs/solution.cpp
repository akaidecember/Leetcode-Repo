// Link: https://leetcode.com/problems/valid-arrangement-of-pairs/description
// Description
// You are given a
// 0-indexed
// 2D integer array
// pairs
// where
// pairs[i] = [start
// i
// , end
// i
// ]
// . An arrangement of
// pairs
// is
// valid
// if for every index
// i
// where
// 1 <= i < pairs.length
// , we have
// end
// i-1
// == start
// i
// .
// Return
// any
// valid arrangement of
// pairs
// .
// Note:
// The inputs will be generated such that there exists a valid arrangement of
// pairs
// .
// Example 1:
// Input:
// pairs = [[5,1],[4,5],[11,9],[9,4]]
// Output:
// [[11,9],[9,4],[4,5],[5,1]]
// Explanation:
// This is a valid arrangement since end
// i-1
// always equals start
// i
// .
// end
// 0
// = 9 == 9 = start
// 1
// end
// 1
// = 4 == 4 = start
// 2
// end
// 2
// = 5 == 5 = start
// 3
// Example 2:
// Input:
// pairs = [[1,3],[3,2],[2,1]]
// Output:
// [[1,3],[3,2],[2,1]]
// Explanation:
// This is a valid arrangement since end
// i-1
// always equals start
// i
// .
// end
// 0
// = 3 == 3 = start
// 1
// end
// 1
// = 2 == 2 = start
// 2
// The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
// Example 3:
// Input:
// pairs = [[1,2],[1,3],[2,1]]
// Output:
// [[1,2],[2,1],[1,3]]
// Explanation:
// This is a valid arrangement since end
// i-1
// always equals start
// i
// .
// end
// 0
// = 2 == 2 = start
// 1
// end
// 1
// = 1 == 1 = start
// 2
// Constraints:
// 1 <= pairs.length <= 10
// 5
// pairs[i].length == 2
// 0 <= start
// i
// , end
// i
// <= 10
// 9
// start
// i
// != end
// i
// No two pairs are exactly the same.
// There
// exists
// a valid arrangement of
// pairs
// .

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> deg;// net outdegree
    inline void build_graph(vector<vector<int>>& pairs){
        for(auto& edge: pairs){
            int start=edge[0], end=edge[1];
            adj[start].push_back(end);
            deg[start]++;
            deg[end]--;
        }
    }

    vector<int> rpath;
    inline void euler(int i){
        vector<int> stk={i};
        while(!stk.empty()){
            i = stk.back();
            if(adj[i].empty()){
                rpath.push_back(i);
                stk.pop_back();
            } 
            else {
                int j=adj[i].back();
                adj[i].pop_back();
                stk.push_back(j);
            }
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        const int e = pairs.size();
        adj.reserve(e);
        deg.reserve(e);
    
        build_graph(pairs);

        int i0=deg.begin()->first;
        //Find start vertex for Euler path 
        for (auto& [v, d]: deg){
            if (d == 1){
                i0=v;
                break;
            } 
        }

        euler(i0);

        vector<vector<int>> ans;
        ans.reserve(e);

        for (int i=rpath.size()-2; i>=0; i--) 
            ans.push_back({rpath[i+1], rpath[i]});

        return ans;
    }
};

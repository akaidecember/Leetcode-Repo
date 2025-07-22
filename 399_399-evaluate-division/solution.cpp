// Link: https://leetcode.com/problems/evaluate-division/description
// Description
// You are given an array of variable pairs
// equations
// and an array of real numbers
// values
// , where
// equations[i] = [A
// i
// , B
// i
// ]
// and
// values[i]
// represent the equation
// A
// i
// / B
// i
// = values[i]
// . Each
// A
// i
// or
// B
// i
// is a string that represents a single variable.
// You are also given some
// queries
// , where
// queries[j] = [C
// j
// , D
// j
// ]
// represents the
// j
// th
// query where you must find the answer for
// C
// j
// / D
// j
// = ?
// .
// Return
// the answers to all queries
// . If a single answer cannot be determined, return
// -1.0
// .
// Note:
// The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
// Note:
// The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.
// Example 1:
// Input:
// equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output:
// [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation:
// Given:
// a / b = 2.0
// ,
// b / c = 3.0
// queries are:
// a / c = ?
// ,
// b / a = ?
// ,
// a / e = ?
// ,
// a / a = ?
// ,
// x / x = ?
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// note: x is undefined => -1.0
// Example 2:
// Input:
// equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output:
// [3.75000,0.40000,5.00000,0.20000]
// Example 3:
// Input:
// equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output:
// [0.50000,2.00000,-1.00000,-1.00000]
// Constraints:
// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= A
// i
// .length, B
// i
// .length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= C
// j
// .length, D
// j
// .length <= 5
// A
// i
// , B
// i
// , C
// j
// , D
// j
// consist of lower case English letters and digits.

class Solution {
public:
    double bfs(map<string, vector<pair<string, double>>> &adj, string source, string target){
        if(adj.find(source) == adj.end() || adj.find(target) == adj.end()) return -1;
        deque<pair<string, double>> q;
        set<string> vst;
        q.push_back({source, 1});
        vst.insert(source);
        while(!q.empty()){
            auto [n, w] = q.front();
            q.pop_front();
            if(n == target){
                return w;
            }
            for(auto& a : adj[n]){
                string nei = a.first;
                double wei = a.second;
                if(vst.find(nei) == vst.end()){
                    q.push_back({nei, w * wei});
                    vst.insert(nei);
                }
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        int i = 0;
        for(const auto& e : equations){
            string a = e[0];
            string b = e[1];
            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1 / values[i++]});
        }
        vector<double> ret;
        for(const auto& q : queries){
            ret.push_back(bfs(adj, q[0], q[1]));
        }
        return ret;
    }
};


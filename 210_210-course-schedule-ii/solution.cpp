// Link: https://leetcode.com/problems/course-schedule-ii/description
// Description
// There are a total of
// numCourses
// courses you have to take, labeled from
// 0
// to
// numCourses - 1
// . You are given an array
// prerequisites
// where
// prerequisites[i] = [a
// i
// , b
// i
// ]
// indicates that you
// must
// take course
// b
// i
// first if you want to take course
// a
// i
// .
// For example, the pair
// [0, 1]
// , indicates that to take course
// 0
// you have to first take course
// 1
// .
// Return
// the ordering of courses you should take to finish all courses
// . If there are many valid answers, return
// any
// of them. If it is impossible to finish all courses, return
// an empty array
// .
// Example 1:
// Input:
// numCourses = 2, prerequisites = [[1,0]]
// Output:
// [0,1]
// Explanation:
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:
// Input:
// numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output:
// [0,2,1,3]
// Explanation:
// There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:
// Input:
// numCourses = 1, prerequisites = []
// Output:
// [0]
// Constraints:
// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= a
// i
// , b
// i
// < numCourses
// a
// i
// != b
// i
// All the pairs
// [a
// i
// , b
// i
// ]
// are
// distinct
// .

class Solution {
public:
    bool solver(int n, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &stk, vector<bool> &recStk){
        vis[n] = true;
        recStk[n] = true;
        for(int i : adj[n]){
            if(!vis[i]){
                if(solver(i, adj, vis, stk, recStk)){
                    return true;
                }
            }
            else if(recStk[i]){
                return true;   
            }
        }
        stk.push(n);
        recStk[n] = false;
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prereq){
        vector<vector<int>> adj(n);
        stack<int> stk;
        vector<int> ret;
        vector<bool> visited(n, false), recStk(n, false);
        for(const auto &p : prereq){
            adj[p[1]].push_back(p[0]);
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(solver(i, adj, visited, stk, recStk)){
                    return {};
                }
            }
        }
        while(!stk.empty()){
            ret.push_back(stk.top());
            stk.pop();
        }
        return ret;
    }
};

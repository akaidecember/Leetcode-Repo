// Link: https://leetcode.com/problems/satisfiability-of-equality-equations/description
// Description
// You are given an array of strings
// equations
// that represent relationships between variables where each string
// equations[i]
// is of length
// 4
// and takes one of two different forms:
// "x
// i
// ==y
// i
// "
// or
// "x
// i
// !=y
// i
// "
// .Here,
// x
// i
// and
// y
// i
// are lowercase letters (not necessarily different) that represent one-letter variable names.
// Return
// true
// if it is possible to assign integers to variable names so as to satisfy all the given equations, or
// false
// otherwise
// .
// Example 1:
// Input:
// equations = ["a==b","b!=a"]
// Output:
// false
// Explanation:
// If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
// There is no way to assign the variables to satisfy both equations.
// Example 2:
// Input:
// equations = ["b==a","a==b"]
// Output:
// true
// Explanation:
// We could assign a = 1 and b = 1 to satisfy both equations.
// Constraints:
// 1 <= equations.length <= 500
// equations[i].length == 4
// equations[i][0]
// is a lowercase letter.
// equations[i][1]
// is either
// '='
// or
// '!'
// .
// equations[i][2]
// is
// '='
// .
// equations[i][3]
// is a lowercase letter.

class Solution {
private:
    vector<int> parent;

public:
    int find(int x){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int a = find(x), b = find(y);

        parent[a] = b;
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);

        int n = equations.size();

        for(auto& e : equations){
            if(e[1] == '!'){
                continue;
            }

            Union(e[0] - 'a', e[3] - 'a');
        }

        for(auto& e : equations){
            if(e[1] == '='){
                continue;
            }

            if(find(e[0] - 'a') == find(e[3] - 'a')){
                return false;
            }
        }

        return true;
    }
};

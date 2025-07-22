// Link: https://leetcode.com/problems/making-a-large-island/description
// Description
// You are given an
// n x n
// binary matrix
// grid
// . You are allowed to change
// at most one
// 0
// to be
// 1
// .
// Return
// the size of the largest
// island
// in
// grid
// after applying this operation
// .
// An
// island
// is a 4-directionally connected group of
// 1
// s.
// Example 1:
// Input:
// grid = [[1,0],[0,1]]
// Output:
// 3
// Explanation:
// Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:
// Input:
// grid = [[1,1],[1,0]]
// Output:
// 4
// Explanation:
// Change the 0 to 1 and make the island bigger, only one island with area = 4.
// Example 3:
// Input:
// grid = [[1,1],[1,1]]
// Output:
// 4
// Explanation:
// Can't change any 0 to 1, only one island with area = 4.
// Constraints:
// n == grid.length
// n == grid[i].length
// 1 <= n <= 500
// grid[i][j]
// is either
// 0
// or
// 1
// .

class UnionFind {
public:
    vector<int> root, Size; 
    UnionFind(int N): root(N), Size(N, 1){
        iota(root.begin(), root.end(), 0);    
    }
    
    int Find(int x) {
        return (x==root[x]) ? x : root[x] = Find(root[x]);
    }

    bool Union(int x, int y) {       
        x=Find(x), y=Find(y);
        if (x == y) return 0; 
        if (Size[x] > Size[y]) {
            Size[x] +=Size[y];
            root[y] = x;
        } 
        else {
            Size[y] += Size[x];
            root[x] = y;
        }       
        return 1;
    } 
};


class Solution {
public:
    int n;
    inline bool inside(int i, int j){
        return 0<=i && i<n && 0<=j && j<n;
    }
    inline int idx(int i,  int j){
        return i*n+j;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        const int N=n*n;
        const int d[5]={0,1,0,-1,0};
        UnionFind G(N);
        int maxSz=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]){
                    int a=idx(i, j), b;
                    int D=(i<n-1)?grid[i+1][j]:0, R=(j<n-1)?grid[i][j+1]:0;
                    if (D>0){// down
                        b=a+n;
                        if (G.Union(a, b))// connect 2 components
                            maxSz=max(maxSz, G.Size[G.Find(a)]);
                    }
                    if (R>0){// right
                        b=a+1;
                        if (G.Union(a, b))// connect 2 components
                            maxSz=max(maxSz, G.Size[G.Find(a)]);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j]==0){
                    int component[4]={N, N, N, N};
                    int cz=0;
                    for( int a=0; a<4; a++){
                        const int r=i+d[a], s=j+d[a+1];
                        if (inside(r, s) && grid[r][s]!=0)
                            component[cz++]=G.Find(idx(r, s));
                    }
                    if (cz==0) continue;
                    sort(component, component+cz);
                    int sz=1+G.Size[component[0]];
                    for (int k=1; k<cz; k++)
                        if (component[k]!=component[k-1]) 
                            sz+=G.Size[component[k]];
                    maxSz=max(maxSz, sz);
                }
            }
        }
        return maxSz;
    }
};


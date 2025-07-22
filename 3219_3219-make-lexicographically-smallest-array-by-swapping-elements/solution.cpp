// Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description
// Description
// You are given a
// 0-indexed
// array of
// positive
// integers
// nums
// and a
// positive
// integer
// limit
// .
// In one operation, you can choose any two indices
// i
// and
// j
// and swap
// nums[i]
// and
// nums[j]
// if
// |nums[i] - nums[j]| <= limit
// .
// Return
// the
// lexicographically smallest array
// that can be obtained by performing the operation any number of times
// .
// An array
// a
// is lexicographically smaller than an array
// b
// if in the first position where
// a
// and
// b
// differ, array
// a
// has an element that is less than the corresponding element in
// b
// . For example, the array
// [2,10,3]
// is lexicographically smaller than the array
// [10,2,3]
// because they differ at index
// 0
// and
// 2 < 10
// .
// Example 1:
// Input:
// nums = [1,5,3,9,8], limit = 2
// Output:
// [1,3,5,8,9]
// Explanation:
// Apply the operation 2 times:
// - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
// - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
// We cannot obtain a lexicographically smaller array by applying any more operations.
// Note that it may be possible to get the same result by doing different operations.
// Example 2:
// Input:
// nums = [1,7,6,18,2,1], limit = 3
// Output:
// [1,6,7,18,1,2]
// Explanation:
// Apply the operation 3 times:
// - Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
// - Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
// - Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
// We cannot obtain a lexicographically smaller array by applying any more operations.
// Example 3:
// Input:
// nums = [1,7,28,19,10], limit = 3
// Output:
// [1,7,28,19,10]
// Explanation:
// [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.
// Constraints:
// 1 <= nums.length <= 10
// 5
// 1 <= nums[i] <= 10
// 9
// 1 <= limit <= 10
// 9

class disjoint {
    vector<int> vs;
    vector<int> pa;

public:
    disjoint(int n) {
        vs.resize(n + 1, 1);
        pa.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            pa[i] = i;
        }
    }

    int findupar(int node) {
        if (node == pa[node]) {
            return node;
        }
        return pa[node] = findupar(pa[node]);
    }

    void unionbysize(int u, int v) {
        int x = findupar(u);
        int y = findupar(v);
        if (x == y)
            return;
        if (vs[x] == vs[y]) {
            vs[x] += vs[y];
            pa[y] = x;
        } else if (vs[x] > vs[y]) {
            vs[x] += vs[y];
            pa[y] = x;
        } else {
            vs[y] += vs[x];
            pa[x] = y;
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        disjoint ds(n);
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
           if(v[i+1].first-v[i].first<=limit) 
           {
             ds.unionbysize(v[i+1].second,v[i].second);
           }
        }
        vector<int> ind(n);
        vector<int> ans(n);
        map<int,int> counter;
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            int fp=ds.findupar(i);
            ind[i]=fp;
            counter[fp]=0;
            mp[fp].push_back(nums[i]);
        }
        for(auto it:mp)
        {
            int x=it.first;
            vector<int> k=it.second;
            sort(k.begin(),k.end());
            mp[x]=k;
        }

        for(int i=0;i<nums.size();i++)
        {
            int up=ind[i];
            int co=counter[up];
          
            ans[i]=mp[up][co];
            counter[up]++;
        }
        return ans;
    }
};

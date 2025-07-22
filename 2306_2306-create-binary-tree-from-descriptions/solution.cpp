// Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/description
// Description
// You are given a 2D integer array
// descriptions
// where
// descriptions[i] = [parent
// i
// , child
// i
// , isLeft
// i
// ]
// indicates that
// parent
// i
// is the
// parent
// of
// child
// i
// in a
// binary
// tree of
// unique
// values. Furthermore,
// If
// isLeft
// i
// == 1
// , then
// child
// i
// is the left child of
// parent
// i
// .
// If
// isLeft
// i
// == 0
// , then
// child
// i
// is the right child of
// parent
// i
// .
// Construct the binary tree described by
// descriptions
// and return
// its
// root
// .
// The test cases will be generated such that the binary tree is
// valid
// .
// Example 1:
// Input:
// descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output:
// [50,20,80,15,17,19]
// Explanation:
// The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.
// Example 2:
// Input:
// descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output:
// [1,2,null,null,3,4]
// Explanation:
// The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.
// Constraints:
// 1 <= descriptions.length <= 10
// 4
// descriptions[i].length == 3
// 1 <= parent
// i
// , child
// i
// <= 10
// 5
// 0 <= isLeft
// i
// <= 1
// The binary tree described by
// descriptions
// is valid.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // {[80] = {first = 19, second = -1}, [50] = {first = 20, second = 80}, [20] = {first = 15, second = 17}}
class Solution {
public:
    TreeNode* helper(unordered_map<int, pair<int,int>> &mp, int curr){
        if(curr == -1) return NULL;
        if(mp.find(curr) == mp.end()) return new TreeNode(curr, NULL, NULL);
        TreeNode* left = helper(mp, mp[curr].first);
        TreeNode* right = helper(mp, mp[curr].second);
        return new TreeNode(curr, left, right);
    }

    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, pair<int,int>> mp;
        set<int> parent, child;
        int root;
        for(const auto& d : desc){
            // Only add the item in the map if not in map
            if(mp.find(d[0]) == mp.end()){
                mp[d[0]] = {-1,-1};
                parent.insert(d[0]);
            }
            // 0 : right child, 1 : left child
            if(d[2] < 1){
                mp[d[0]].second = d[1];
            }
            else{
                mp[d[0]].first = d[1];
            }
            child.insert(d[1]);
        }
        for(const auto& p : parent){
            if (!child.count(p)){
                root = p;
                break;
            }
        }    
        return helper(mp, root);
    }
};

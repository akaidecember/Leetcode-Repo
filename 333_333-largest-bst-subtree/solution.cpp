// Link: https://leetcode.com/problems/largest-bst-subtree/description
// Description
// Given the root of a binary tree, find the largest
// subtree
// , which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.
// A
// Binary Search Tree (BST)
// is a tree in which all the nodes follow the below-mentioned properties:
// The left subtree values are less than the value of their parent (root) node's value.
// The right subtree values are greater than the value of their parent (root) node's value.
// Note:
// A subtree must include all of its descendants.
// Example 1:
// Input:
// root = [10,5,15,1,8,null,7]
// Output:
// 3
// Explanation:
// The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.
// Example 2:
// Input:
// root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
// Output:
// 2
// Constraints:
// The number of nodes in the tree is in the range
// [0, 10
// 4
// ]
// .
// -10
// 4
// <= Node.val <= 10
// 4
// Follow up:
// Can you figure out ways to solve it with
// O(n)
// time complexity?

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
class Solution {
public:
    tuple<int,int,int> dfs(TreeNode* root, int &ret){
        if(!root) return {0, INT_MAX, INT_MIN};
        auto [lc, lmn, lmx] = dfs(root->left, ret);
        auto [rc, rmn, rmx] = dfs(root->right, ret);
        int count = rc + lc + 1;
        if(root->val > lmx && root->val < rmn){
            ret = max(ret, count);
            return {count, min({root->val, lmn, rmn}), max({root->val, rmx, lmx})};
        }
        return {0, INT_MIN, INT_MAX};
    }

    int largestBSTSubtree(TreeNode* root) {
        int ret = 0;
        dfs(root, ret);
        return ret;
    }
};

// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description
// Description
// Given two integer arrays,
// preorder
// and
// postorder
// where
// preorder
// is the preorder traversal of a binary tree of
// distinct
// values and
// postorder
// is the postorder traversal of the same tree, reconstruct and return
// the binary tree
// .
// If there exist multiple answers, you can
// return any
// of them.
// Example 1:
// Input:
// preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output:
// [1,2,3,4,5,6,7]
// Example 2:
// Input:
// preorder = [1], postorder = [1]
// Output:
// [1]
// Constraints:
// 1 <= preorder.length <= 30
// 1 <= preorder[i] <= preorder.length
// All the values of
// preorder
// are
// unique
// .
// postorder.length == preorder.length
// 1 <= postorder[i] <= postorder.length
// All the values of
// postorder
// are
// unique
// .
// It is guaranteed that
// preorder
// and
// postorder
// are the preorder traversal and postorder traversal of the same binary tree.

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int index = 0;
        return construct(pre, post, index, 0, pre.size() - 1);
    }
    
private:
    TreeNode* construct(vector<int>& pre, vector<int>& post, int& index, int l, int h) {
        if (index >= pre.size() || l > h) 
            return nullptr;

        TreeNode* root = new TreeNode(pre[index++]);
        if (l == h) return root;

        int i = l;
        while (i <= h && post[i] != pre[index]) i++;

        if (i <= h) {
            root->left = construct(pre, post, index, l, i);
            root->right = construct(pre, post, index, i + 1, h - 1);
        }

        return root;
    }
};

// Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/description
// Description
// Given the
// root
// of a binary search tree (BST) with duplicates, return
// all the
// mode(s)
// (i.e., the most frequently occurred element) in it
// .
// If the tree has more than one mode, return them in
// any order
// .
// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys
// less than or equal to
// the node's key.
// The right subtree of a node contains only nodes with keys
// greater than or equal to
// the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1:
// Input:
// root = [1,null,2,2]
// Output:
// [2]
// Example 2:
// Input:
// root = [0]
// Output:
// [0]
// Constraints:
// The number of nodes in the tree is in the range
// [1, 10
// 4
// ]
// .
// -10
// 5
// <= Node.val <= 10
// 5
// Follow up:
// Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

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
private:
    vector<int> ret;
    int prev = 0, counter = 0, max_val = 0;

public:
    void inorder(TreeNode* root){
        if(root == nullptr){
            return;
        }

        inorder(root->left);

        counter = (prev == root->val) ? counter + 1 : 1;
        
        if(counter == max_val){
            ret.emplace_back(root->val);
        }
        else if(counter > max_val){
            max_val = max(max_val, counter);
            ret = {root->val};
        }

        prev = root->val;
        inorder(root->right);
        
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ret;
    }
};

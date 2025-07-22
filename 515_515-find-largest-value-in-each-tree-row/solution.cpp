// Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/description
// Description
// Given the
// root
// of a binary tree, return
// an array of the largest value in each row
// of the tree
// (0-indexed)
// .
// Example 1:
// Input:
// root = [1,3,2,5,3,null,9]
// Output:
// [1,3,9]
// Example 2:
// Input:
// root = [1,2,3]
// Output:
// [1,3]
// Constraints:
// The number of nodes in the tree will be in the range
// [0, 10
// 4
// ]
// .
// -2
// 31
// <= Node.val <= 2
// 31
// - 1

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
    void preOrder(TreeNode* Node,  int level, vector<int> &ret){
        if (Node == NULL){
            return;
        }

        if (ret.size()<=level){
            ret.push_back(INT_MIN);
        }

        ret[level] = max(ret[level], Node->val);

        preOrder(Node->left, level+1, ret);
        preOrder(Node->right, level+1, ret);     
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;

        if (root == NULL){
            return {};
        }

        preOrder(root, 0, ret);
        return ret;
    }
};

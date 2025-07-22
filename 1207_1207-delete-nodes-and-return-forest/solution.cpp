// Link: https://leetcode.com/problems/delete-nodes-and-return-forest/description
// Description
// Given the
// root
// of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in
// to_delete
// , we are left with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest. You may return the result in any order.
// Example 1:
// Input:
// root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output:
// [[1,2,null,4],[6],[7]]
// Example 2:
// Input:
// root = [1,2,4,null,3], to_delete = [3]
// Output:
// [[1,2,4]]
// Constraints:
// The number of nodes in the given tree is at most
// 1000
// .
// Each node has a distinct value between
// 1
// and
// 1000
// .
// to_delete.length <= 1000
// to_delete
// contains distinct values between
// 1
// and
// 1000
// .

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
    TreeNode* dfs(TreeNode* curr, unordered_set<int> &del, unordered_set<TreeNode*> &ret){
        if (curr == NULL) return NULL;
        TreeNode* node = curr;
        if(del.find(node->val) != del.end()){
            node = NULL;
            if(ret.find(curr) != ret.end()){
                ret.erase(curr);
            }
            if(curr->left != NULL) ret.insert(curr->left);
            if(curr->right != NULL) ret.insert(curr->right);
        }
        curr->left = dfs(curr->left, del, ret);
        curr->right = dfs(curr->right, del, ret);
        return node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(begin(to_delete), end(to_delete));
        unordered_set<TreeNode*> ret;
        ret.insert(root);
        dfs(root, st, ret);
        return vector<TreeNode*>(ret.begin(), ret.end());
    }
};

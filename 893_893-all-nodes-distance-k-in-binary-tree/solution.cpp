// Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description
// Description
// Given the
// root
// of a binary tree, the value of a target node
// target
// , and an integer
// k
// , return
// an array of the values of all nodes that have a distance
// k
// from the target node.
// You can return the answer in
// any order
// .
// Example 1:
// Input:
// root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output:
// [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
// Example 2:
// Input:
// root = [1], target = 1, k = 3
// Output:
// []
// Constraints:
// The number of nodes in the tree is in the range
// [1, 500]
// .
// 0 <= Node.val <= 500
// All the values
// Node.val
// are
// unique
// .
// target
// is the value of one of the nodes in the tree.
// 0 <= k <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findDistance(TreeNode* root, int k, vector<int> &ret){
        if(!root) return;
        if(k == 0){
            ret.push_back(root->val);
            return;
        }
        findDistance(root->left, k-1, ret);
        findDistance(root->right, k-1, ret);
    }

    int dfs(TreeNode* &root, TreeNode* &target, int k, vector<int> &ret){
        if(!root) return -1;
        if(root == target){
            findDistance(root, k, ret);
            return 0;
        }
        auto left = dfs(root->left, target, k, ret);
        if(left != -1){
            if(left + 1 == k) ret.push_back(root->val);
            else findDistance(root->right, k - left - 2, ret);
            return left + 1;
        }
        auto right = dfs(root->right, target, k, ret);
        if(right != -1){
            if(right + 1 == k) ret.push_back(root->val);
            else findDistance(root->left, k - right - 2, ret);
            return right + 1;
        }
        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0){
            return {target->val};
        }
        vector<int> ret;
        dfs(root, target, k, ret);
        return ret;
    }
};

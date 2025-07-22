// Link: https://leetcode.com/problems/cousins-in-binary-tree-ii/description
// Description
// Given the
// root
// of a binary tree, replace the value of each node in the tree with the
// sum of all its cousins' values
// .
// Two nodes of a binary tree are
// cousins
// if they have the same depth with different parents.
// Return
// the
// root
// of the modified tree
// .
// Note
// that the depth of a node is the number of edges in the path from the root node to it.
// Example 1:
// Input:
// root = [5,4,9,1,10,null,7]
// Output:
// [0,0,0,7,7,null,11]
// Explanation:
// The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 5 does not have any cousins so its sum is 0.
// - Node with value 4 does not have any cousins so its sum is 0.
// - Node with value 9 does not have any cousins so its sum is 0.
// - Node with value 1 has a cousin with value 7 so its sum is 7.
// - Node with value 10 has a cousin with value 7 so its sum is 7.
// - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
// Example 2:
// Input:
// root = [3,1,2]
// Output:
// [0,0,0]
// Explanation:
// The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
// - Node with value 3 does not have any cousins so its sum is 0.
// - Node with value 1 does not have any cousins so its sum is 0.
// - Node with value 2 does not have any cousins so its sum is 0.
// Constraints:
// The number of nodes in the tree is in the range
// [1, 10
// 5
// ]
// .
// 1 <= Node.val <= 10
// 4

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }

        queue<TreeNode*> q;
        int n, nxt_sum, curr_sum = root->val;
        struct TreeNode* node;

        q.push(root);

        while(!q.empty()){
            n = q.size();
            nxt_sum = 0;

            for(int i = 0; i < n; i++){
                node = q.front();
                q.pop();

                node->val = curr_sum - node->val;

                if(node->left){
                    q.push(node->left);
                    nxt_sum += node->left->val;
                }
                if(node->right){
                    q.push(node->right);
                    nxt_sum += node->right->val;
                }
                if(node->left and node->right){
                    node->right->val = node->left->val = node->left->val + node->right->val;
                }
            }
            curr_sum = nxt_sum;
        }

        return root;
    }
};

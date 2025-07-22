// Link: https://leetcode.com/problems/most-frequent-subtree-sum/description
// Description
// Given the
// root
// of a binary tree, return the most frequent
// subtree sum
// . If there is a tie, return all the values with the highest frequency in any order.
// The
// subtree sum
// of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
// Example 1:
// Input:
// root = [5,2,-3]
// Output:
// [2,-3,4]
// Example 2:
// Input:
// root = [5,2,-5]
// Output:
// [2]
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
    map<int,int>mp;

public:
    int findSum(TreeNode* root){
        if(!root){
            return 0;
        }

        int lsum = findSum(root->left);
        int rsum = findSum(root->right);
        mp[root->val + lsum + rsum]++;

        return root->val + lsum + rsum;
    }


    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;

        findSum(root);

        priority_queue<pair<int,int>>q;

        for(auto it=mp.begin(); it != mp.end(); it++){
            q.push({it->second, it->first});
        }

        int max_freq=q.top().first;

        while(!q.empty() && q.top().first == max_freq){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};

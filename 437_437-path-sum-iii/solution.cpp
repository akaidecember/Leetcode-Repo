// Link: https://leetcode.com/problems/path-sum-iii/description
// Description
// Given the
// root
// of a binary tree and an integer
// targetSum
// , return
// the number of paths where the sum of the values along the path equals
// targetSum
// .
// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
// Example 1:
// Input:
// root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output:
// 3
// Explanation:
// The paths that sum to 8 are shown.
// Example 2:
// Input:
// root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output:
// 3
// Constraints:
// The number of nodes in the tree is in the range
// [0, 1000]
// .
// -10
// 9
// <= Node.val <= 10
// 9
// -1000 <= targetSum <= 1000

/**
 * Definition for a binary tree root.
 * struct Treeroot {
 *     int val;
 *     Treeroot *left;
 *     Treeroot *right;
 *     Treeroot() : val(0), left(nullptr), right(nullptr) {}
 *     Treeroot(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Treeroot(int x, Treeroot *left, Treeroot *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solver(TreeNode *root, int t, long &ret, map<long, long> &mp, long sum){
        if(!root){
            return;
        }
        sum += root->val;
        if(mp.find(sum - t) != mp.end()){
            ret += mp[sum - t];
        }
        if(t == sum){
            ret++;
        }
        mp[sum]++;
        solver(root->left, t, ret, mp, sum);
        solver(root->right, t, ret, mp, sum);
        mp[sum]--;
        sum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        map<long, long> mp;
        long ret = 0;
        solver(root, targetSum, ret, mp, 0);
        return ret;
    }
};

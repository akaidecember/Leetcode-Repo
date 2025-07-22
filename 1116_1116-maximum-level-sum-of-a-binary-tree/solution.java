// Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description
// Description
// Given the
// root
// of a binary tree, the level of its root is
// 1
// , the level of its children is
// 2
// , and so on.
// Return the
// smallest
// level
// x
// such that the sum of all the values of nodes at level
// x
// is
// maximal
// .
// Example 1:
// Input:
// root = [1,7,0,7,-8,null,null]
// Output:
// 2
// Explanation:
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
// Example 2:
// Input:
// root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output:
// 2
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
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private void sumLevels(TreeNode root, int level, ArrayList<Integer> sum){
        if(root == null){
            return;
        }
        if(level >= sum.size()){
            sum.add(root.val);
        }
        else{
            sum.set(level, sum.get(level) + root.val);
        }

        sumLevels(root.left, level + 1, sum);
        sumLevels(root.right, level + 1, sum);
    }

    public int maxLevelSum(TreeNode root) {
        ArrayList<Integer> sum = new ArrayList<>();
        sum.add(0);
        sumLevels(root, 0, sum);

        int ret = 0, val = Integer.MIN_VALUE;
        for(int i = 0; i < sum.size(); i++){
            if(sum.get(i) > val){
                val = sum.get(i);
                ret = i + 1;
            }
        }        

        return ret;
    }
}

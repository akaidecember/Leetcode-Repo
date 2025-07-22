// Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description
// Description
// You are given the
// root
// of a
// binary tree
// with
// n
// nodes. Each node is uniquely assigned a value from
// 1
// to
// n
// . You are also given an integer
// startValue
// representing the value of the start node
// s
// , and a different integer
// destValue
// representing the value of the destination node
// t
// .
// Find the
// shortest path
// starting from node
// s
// and ending at node
// t
// . Generate step-by-step directions of such path as a string consisting of only the
// uppercase
// letters
// 'L'
// ,
// 'R'
// , and
// 'U'
// . Each letter indicates a specific direction:
// 'L'
// means to go from a node to its
// left child
// node.
// 'R'
// means to go from a node to its
// right child
// node.
// 'U'
// means to go from a node to its
// parent
// node.
// Return
// the step-by-step directions of the
// shortest path
// from node
// s
// to node
// t
// .
// Example 1:
// Input:
// root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output:
// "UURL"
// Explanation:
// The shortest path is: 3 → 1 → 5 → 2 → 6.
// Example 2:
// Input:
// root = [2,1], startValue = 2, destValue = 1
// Output:
// "L"
// Explanation:
// The shortest path is: 2 → 1.
// Constraints:
// The number of nodes in the tree is
// n
// .
// 2 <= n <= 10
// 5
// 1 <= Node.val <= n
// All the values in the tree are
// unique
// .
// 1 <= startValue, destValue <= n
// startValue != destValue

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
     queue<TreeNode*> q;
        q.push(root);
        TreeNode* start_node = nullptr;
        while (!q.empty()) {
            TreeNode* cur_node = q.front();
            q.pop();

            if (cur_node->val == startValue) {
                start_node = cur_node;
                break;
            }

            if (cur_node->left) {
                q.push(cur_node->left);
            }
            if (cur_node->right) {
                q.push(cur_node->right);
            }
        }
        unordered_map<int, TreeNode*> nodes_parents;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur_node = q.front();
            q.pop();

            if (cur_node->left) {
                nodes_parents[cur_node->left->val] = cur_node;
                q.push(cur_node->left);
            }
            if (cur_node->right) {
                nodes_parents[cur_node->right->val] = cur_node;
                q.push(cur_node->right);
            }
        }
        unordered_set<TreeNode*> visited;
        q.push(start_node);
        unordered_map<TreeNode*, pair<TreeNode*, char>> tracked_path;
        TreeNode* destination_node = nullptr;
        while (!q.empty()) {
            TreeNode* cur_node = q.front();
            q.pop();
            visited.insert(cur_node);

            if (cur_node->val == destValue) {
                destination_node = cur_node;
                break;
            }
            if (nodes_parents.find(cur_node->val) != nodes_parents.end() && visited.find(nodes_parents[cur_node->val]) == visited.end()) {
                TreeNode* parent = nodes_parents[cur_node->val];
                q.push(parent);
                tracked_path[parent] = make_pair(cur_node, 'U'); 
            }

            if (cur_node->left && visited.find(cur_node->left) == visited.end()) {
                q.push(cur_node->left);
                tracked_path[cur_node->left] = make_pair(cur_node, 'L'); 
            }

            if (cur_node->right && visited.find(cur_node->right) == visited.end()) {
                q.push(cur_node->right);
                tracked_path[cur_node->right] = make_pair(cur_node, 'R'); 
            }
        }
        stack<char> result_path;
        TreeNode* cur_node = destination_node;
        while (cur_node != start_node) {
            auto it = tracked_path.find(cur_node);
            if (it != tracked_path.end()) {
                result_path.push(it->second.second); 
                cur_node = it->second.first;
            }
        }
        string res;
        while (!result_path.empty()) {
            res += result_path.top();
            result_path.pop();
        }
        return res;   
    }
};

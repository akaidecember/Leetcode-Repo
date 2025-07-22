// Link: https://leetcode.com/problems/palindrome-linked-list/description
// Description
// Given the
// head
// of a singly linked list, return
// true
// if it is a
// palindrome
// or
// false
// otherwise
// .
// Example 1:
// Input:
// head = [1,2,2,1]
// Output:
// true
// Example 2:
// Input:
// head = [1,2]
// Output:
// false
// Constraints:
// The number of nodes in the list is in the range
// [1, 10
// 5
// ]
// .
// 0 <= Node.val <= 9
// Follow up:
// Could you do it in
// O(n)
// time and
// O(1)
// space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode *curr = head;
        while(curr){
            stk.push(curr->val);
            curr = curr->next;
        }   
        while(head && head->val == stk.top()){
            stk.pop();
            head = head->next;
        }
        return head == NULL;
    }
};

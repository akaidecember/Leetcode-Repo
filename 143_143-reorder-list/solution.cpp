// Link: https://leetcode.com/problems/reorder-list/description
// Description
// You are given the head of a singly linked-list. The list can be represented as:
// L
// 0
// → L
// 1
// → … → L
// n - 1
// → L
// n
// Reorder the list to be on the following form:
// L
// 0
// → L
// n
// → L
// 1
// → L
// n - 1
// → L
// 2
// → L
// n - 2
// → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.
// Example 1:
// Input:
// head = [1,2,3,4]
// Output:
// [1,4,2,3]
// Example 2:
// Input:
// head = [1,2,3,4,5]
// Output:
// [1,5,2,4,3]
// Constraints:
// The number of nodes in the list is in the range
// [1, 5 * 10
// 4
// ]
// .
// 1 <= Node.val <= 1000

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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;  
        ListNode* prev = NULL;  
        while(temp != NULL){  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }
        slow->next = NULL;
        temp = head;
        while(temp && prev){
            ListNode *temp_n = temp->next;
            ListNode *prev_n = prev->next;
            temp->next = prev;
            prev->next = temp_n;
            temp = temp_n;
            prev = prev_n;
        }
    }
};

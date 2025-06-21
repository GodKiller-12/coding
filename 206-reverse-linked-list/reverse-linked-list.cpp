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
 #define Node ListNode*

class Solution {
public:
    Node rec(Node head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node newHead = rec(head->next); 
        head->next->next = head;       
        head->next = NULL;               
        return newHead;                 
    }

    ListNode* reverseList(ListNode* head) {
        return rec(head);
    }
};

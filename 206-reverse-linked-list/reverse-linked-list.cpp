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
 #define Node ListNode *
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    Node prev = NULL;
    Node temp = head ;
    while(temp!=NULL){
    Node front = temp->next;
    temp->next = prev;
    prev = temp ;
    temp = front ;
    }
    delete temp;
    return prev ;
    }
};
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL || head==NULL){
            return NULL ;
        }
        Node slow = head ;
        Node fast = head ;
        fast = fast ->next->next;
        while(fast!=NULL && fast ->next != NULL ){
            slow = slow->next ;
            fast = fast ->next->next ;
        }
        Node mid = slow->next ;
        slow->next = slow->next->next ;
        delete mid;
        return head;
        
    }
};
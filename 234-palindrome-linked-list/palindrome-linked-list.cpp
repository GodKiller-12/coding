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
Node solve(Node head){
    if(head == NULL || head->next == NULL){
        return head ;
    }
    Node ans = solve(head->next);
    head ->next->next = head ;
    head->next = NULL;
    return ans ;
}

    bool isPalindrome(ListNode* head) {
      Node slow = head ;
      Node fast = head ;
      while(fast->next != NULL && fast->next->next != NULL){
        slow = slow ->next ;
        fast = fast->next->next ;
      }
      Node temp = solve(slow->next);
      Node start = head ;
      while(temp!= NULL){
        if(temp->val!= start->val){
            return false ;
        }
        temp = temp->next;
        start = start->next ;
      }
      return true ;
    }
};
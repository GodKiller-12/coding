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
    bool isPalindrome(ListNode* head) {
        map<Node ,Node>mp;
        Node temp = head;
        int count = 0;
        while(temp->next!=NULL){
            Node curr = temp ;
            temp = temp->next ;
            mp[temp] = curr ;
        }
       Node f = head;
       while(f->val==temp->val){
        f = f->next ;
        temp = mp[temp];
        if(f==temp) return true ;
       }
       return false ;
    }
};
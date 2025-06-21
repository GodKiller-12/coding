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
    ListNode* oddEvenList(ListNode* head) {
        if(head== NULL) return NULL;
        if(head->next == NULL || head->next->next== NULL) return head ;
        vector<int>ans ;
        Node temp = head ;
        ans.push_back(head->val);
        while(temp->next!=NULL && temp->next->next!=NULL){
            temp = temp->next->next;
            ans.push_back(temp->val);
        }
        temp = head ->next ;
        ans.push_back(temp->val);
         while(temp->next!=NULL && temp->next->next!=NULL){
             temp = temp->next->next;
            ans.push_back(temp->val);
        }
        // for(auto i:ans){
        //     cout<<i<<" ";
        // }
        int i = 0;
        temp = head ;
         while(temp!=NULL){
            temp->val = ans[i];
            temp = temp->next;
            i++;
        }
        return head ;
    }
};
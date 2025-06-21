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
#define Node ListNode*
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int>st;
        int count = 0;
        Node temp = head ;
        while(count <right){
            count ++;
            if(count <=right && count >=left){
                st.push(temp->val);
            }
            temp = temp ->next ;
        }
         temp = head ;
         count = 0;
        while(count <right){
            count ++;
            if(count <=right && count >=left){
               temp->val = st.top();
               st.pop();
            }
            temp = temp ->next ;
        }
        return head ;
    }
};
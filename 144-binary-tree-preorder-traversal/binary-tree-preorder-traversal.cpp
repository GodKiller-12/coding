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
 #define node TreeNode* 
 #define pb push_back
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        stack<node>st;
        vector<int>ans ;
        st.push(root);
        while(!st.empty()){
           node temp = st.top();
           st.pop();
           ans.pb(temp->val);
           if(temp->right!=NULL){
            st.push(temp->right);
           }
           if(temp->left!=NULL){
            st.push(temp->left);
           }
           
        }
        return ans ;
    }
};
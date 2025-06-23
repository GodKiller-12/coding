class Solution {
public:
#define Node TreeNode*
#define pb push_back
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
      vector<int>in;
      vector<int>po;
      vector<int>pre;
      stack<pair<int,Node>>st;
      st.push({1,root});
      while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.first == 1){
            pre.pb(it.second->val);
            st.push({2,it.second});
            if(it.second->left!=NULL){
                st.push({1,it.second->left});
            }
        }
        else if(it.first == 2){
               in.pb(it.second->val);
            st.push({3,it.second});
            if(it.second->right!=NULL){
                st.push({1,it.second->right});
            }
        }
        else{
            po.pb(it.second->val);
        }
      }
return pre;



    }
};

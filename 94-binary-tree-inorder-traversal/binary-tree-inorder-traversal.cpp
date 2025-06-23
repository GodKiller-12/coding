class Solution {
public:
#define Node TreeNode*
#define pb push_back
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<Node> st;
        Node curr = root;
        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            ans.pb(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};

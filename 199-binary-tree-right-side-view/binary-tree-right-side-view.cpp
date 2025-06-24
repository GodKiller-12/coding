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
 #define Node TreeNode*
 #define pb push_back
class Solution {
public:
vector<int>rns ;
    vector<int> rightSideView(TreeNode* root) {
            if(root==NULL){
            return {};
        }
        queue<Node>q;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            vector<int>temp;
            while(count--){
                auto x = q.front(); 
                if(count==0){
                rns.pb(x->val);
                }
                if(x->left!=NULL){
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    q.push(x->right);
                }
                q.pop();
            }
        }
        return rns ;
    }
};
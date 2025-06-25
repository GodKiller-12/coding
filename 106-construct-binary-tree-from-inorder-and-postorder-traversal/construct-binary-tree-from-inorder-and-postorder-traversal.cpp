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
 class Solution {
public:
 Node rec( int i , int j ,vector<int>&in , vector<int>&pre,int r, int c ,map<int,int>&mp){
    if(i>j || r>c){
        return NULL ;
    }
    Node tmp = new TreeNode(pre[c]);
    tmp->right = rec(mp[tmp->val]+1,j,in,pre,c-(j-mp[tmp->val]),c-1 ,mp);
    tmp->left = rec(i,mp[tmp->val]-1,in,pre,r,c-(j-mp[tmp->val])-1,mp);
    return tmp;
}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int > mp;
        int n = inorder.size();
        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return rec(0,n-1,inorder,postorder,0,n-1,mp);
    }
    
};
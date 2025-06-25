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
    Node tmp = new TreeNode(pre[r]);
    tmp->left = rec(i,mp[tmp->val]-1,in,pre,r +1,r+j-i,mp);
    tmp->right = rec(mp[tmp->val]+1,j,in,pre,r + mp[tmp->val]-i + 1 ,c,mp);
    return tmp;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int > mp;
        int n = inorder.size();
        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return rec(0,n-1,inorder,preorder,0,n-1,mp);
    }
};
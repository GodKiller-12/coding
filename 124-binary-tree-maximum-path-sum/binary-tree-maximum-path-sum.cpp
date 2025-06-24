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
int maxi = INT_MIN;
int rec(Node root){
    if(!root){
        return 0;
    }
    if(root->right == NULL && root->left==NULL){
        maxi = max(maxi,root->val);
        return max(0,root->val) ;
    }
    int leftsum = rec(root->left) ;
    int rightsum = rec(root->right) ;
     maxi = max(maxi,leftsum + rightsum + root->val);
    return max({leftsum+root->val,rightsum + root->val,0});
}
    int maxPathSum(TreeNode* root) {
        int n = rec(root);
        return maxi;
    }
};
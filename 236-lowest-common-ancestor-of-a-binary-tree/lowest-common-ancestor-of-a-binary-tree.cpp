/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #define Node TreeNode*
class Solution {
public:
Node rec(Node root , Node p , Node q){
    if(!root || root==p || root==q){
        return root ;
    }
    Node left = rec(root->left,p,q);
    Node right = rec(root->right,p,q);
    if(!left){
        return right ;
    }
    if(!right){
        return left ;
    }
        return root ;
    
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return rec(root,p,q);
    }
};
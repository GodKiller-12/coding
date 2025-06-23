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
int rec(Node root,bool &ans){
        if(!root) return 0;
        int leftheight = rec(root->left,ans);
        int rightheight = rec(root->right,ans);
        if( abs(leftheight - rightheight) >1 ){
             ans = false ;
        }
        return 1 + max(leftheight,rightheight);
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true ;
        int num = rec(root,ans);
        return ans ;
    }
};
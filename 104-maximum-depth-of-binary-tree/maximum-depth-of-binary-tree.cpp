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
    int rec(Node root){
        if(!root) return 0;
        if(root->right == nullptr && root->left == NULL){
            return 1;
        }
        int leftheight = rec(root->left);
        int rightheight = rec(root->right);
        int height = 1 + max(leftheight,rightheight);
        return height ;
    }
    int maxDepth(TreeNode* root) {
        return rec(root);
    }
};
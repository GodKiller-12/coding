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
int rec(Node root,int &dim){
        if(!root) return 0;
        int leftheight = rec(root->left,dim);
        int rightheight = rec(root->right,dim);
        dim = max(dim,leftheight+rightheight);
        return 1 + max(leftheight,rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dim = 0;
         int num = rec(root,dim);
         return dim;
    }
};
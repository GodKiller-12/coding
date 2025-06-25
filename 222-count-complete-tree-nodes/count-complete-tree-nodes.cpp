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
class Solution {
public:
   int h ;
     int rec(TreeNode* root){
     if(root ==NULL){
        return 0;
     }
     int ans = 0;
     int left = 1 + rec(root->left);
     int right = 1 + rec (root->right);
     return max(left,right);
    }

    int func(TreeNode *node,int level){
       if(!node)
         { return 0;}

        int count = 1+func(node->left,level+1) + func(node->right,level +1 );

        return count ;

    }

    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
     
        int height = rec(root);
           h = height ;
        int count = pow(2,height) - 1;
        int k =  func(root,1);
        return k ;
       

    }
};
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
    int func(Node node){
       if(!node)
         { return 0;}
         int l = getleft(node->left);
         int r = getright(node->right);
         if(l == r){
            return (1<<l) - 1 ;
         }
        int count = 1+func(node->left) + func(node->right);
        return count ;
    }
    int getleft(Node node){
        int cnt = 1;
        while(node){
            cnt ++;
            node = node->left ;
        }
        return cnt ;
    }
    int getright(Node node ){
        int cnt = 1;
        while(node){
            cnt ++;
            node = node->right;
        }
        return cnt ;
    }
    int countNodes(TreeNode* root) {
        return func(root);
    }
};
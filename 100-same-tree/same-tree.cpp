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
bool rec(Node p, Node q){
    if(!p && !q){
        return true ;
    }
    if(!p || !q){
        return false ;
    }
        if(p->val != q->val){
           return false ;
        }
        return  rec(p->left,q->left) && rec(p->right,q->right); ;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return rec(p,q);
    }
};
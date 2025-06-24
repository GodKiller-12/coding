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
bool check(Node p , Node q){
    if(!p && !q){
        return true;
    }
    if(!p || !q){
        return false ;
    }
    if(p->val != q->val) return false ;
    return check(p->right , q->left ) && check(p->left,q->right);
}
    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
};
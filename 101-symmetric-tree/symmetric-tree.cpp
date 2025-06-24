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
bool check(Node p, Node q) {
    if (!p || !q) return p == q;
    return (p->val == q->val) &&
           check(p->left, q->right) &&
           check(p->right, q->left);
}
    bool isSymmetric(TreeNode* root) {
        bool ans = check(root,root);
        root->left = nullptr ;
        root->right = nullptr;
        return ans ;
    }
};
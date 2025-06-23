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
    int h(Node root){
        if(!root) return 0;
        return 1 + max(h(root->right),h(root->left));
    }
    int maxDepth(TreeNode* root) {
        return h(root);
    }
};
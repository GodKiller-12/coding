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
    void dfs(TreeNode* root, int row, int col, map<int, map<int, multiset<int>>>& nodes) {
        if (!root) return;

        nodes[col][row].insert(root->val);

        dfs(root->left, row + 1, col - 1, nodes);  // left -> col-1
        dfs(root->right, row + 1, col + 1, nodes); // right -> col+1
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        dfs(root, 0, 0, nodes);

        vector<vector<int>> result;

        for (auto& colPair : nodes) {
            vector<int> col;
            for (auto& rowPair : colPair.second) {
                col.insert(col.end(), rowPair.second.begin(), rowPair.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};

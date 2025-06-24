#define Node TreeNode* 
class Solution {
public:
    void rec(Node root, int x, int y, map<pair<int, int>, vector<int>>& mp) {
        if (!root) return;
        mp[{x, y}].push_back(root->val);
        rec(root->left, x + 1, y - 1, mp);
        rec(root->right, x + 1, y + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, vector<int>> mp;
        rec(root, 0, 0, mp);

        int mini = INT_MAX, maxi = INT_MIN;
        for (auto& i : mp) {
            mini = min(mini, i.first.second);
            maxi = max(maxi, i.first.second);
        }

        int n = maxi - mini;
        vector<vector<int>> ans(n + 1);

        for (auto& i : mp) {
            sort(i.second.begin(), i.second.end()); 
            for (int val : i.second) {
                ans[i.first.second - mini].push_back(val);
            }
        }

        return ans;
    }
};

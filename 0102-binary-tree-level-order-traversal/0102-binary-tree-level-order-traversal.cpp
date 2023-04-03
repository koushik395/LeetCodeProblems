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
    vector<vector<int>> ans;
    void levelOrderRecursive(TreeNode* root, int level, vector<vector<int>>& ans) {
    if (root == nullptr)
        return;
    
    if (level == ans.size()) {
        ans.push_back({root->val});
    } else {
        ans[level].push_back(root->val);
    }
    
    levelOrderRecursive(root->left, level + 1, ans);
    levelOrderRecursive(root->right, level + 1, ans);
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrderRecursive(root,0,ans);
        return ans;
    }
};
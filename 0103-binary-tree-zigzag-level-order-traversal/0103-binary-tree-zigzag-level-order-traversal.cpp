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
    void traverse(TreeNode* node, int level, vector<vector<int>>& result) {
        if (node == nullptr) {
            return;
        }
        
        if (level == result.size()) {
            result.push_back({});
        }
        
        if (level % 2 == 0) {
            result[level].push_back(node->val);
        } else {
            result[level].insert(result[level].begin(), node->val);
        }
        
        traverse(node->left, level + 1, result);
        traverse(node->right, level + 1, result);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        traverse(root, 0, result);
        return result;
    }
};
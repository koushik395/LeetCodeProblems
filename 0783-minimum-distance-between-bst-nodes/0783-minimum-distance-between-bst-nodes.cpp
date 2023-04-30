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
private:
    TreeNode* previous = nullptr;
    int mini = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return mini;
    }
    void inOrder(TreeNode* root) {
        if (root == nullptr) return;
        inOrder(root->left);
        if (previous != nullptr) {
            mini = min(mini, root->val - previous->val);
        }
        previous = root;
        inOrder(root->right);
    }
};
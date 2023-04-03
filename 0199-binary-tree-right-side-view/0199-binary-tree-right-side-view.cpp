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
    vector<int> ans;
    void levelOrderRecursive(TreeNode* root, int level) {
        if (root == nullptr)
            return;

        if (level == ans.size()) {
            ans.push_back(root->val);
        }
    
        levelOrderRecursive(root->right, level + 1);
        levelOrderRecursive(root->left, level + 1);
}
    vector<int> rightSideView(TreeNode* root) {
        levelOrderRecursive(root,0);
        return ans;
    }
};
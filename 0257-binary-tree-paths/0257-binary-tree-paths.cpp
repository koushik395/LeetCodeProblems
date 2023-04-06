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
    vector<string> ans;
    void generate(TreeNode* root,string str)
    {
        if(!root->left && !root->right)
        {
            ans.push_back(str);
            return;
        }
        if(root->left) generate(root->left,str+"->"+to_string(root->left->val));
        if(root->right) generate(root->right,str+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        string str = "";
        generate(root,str+to_string(root->val));
        return ans;
    }
};
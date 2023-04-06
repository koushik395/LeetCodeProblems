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
    void check(TreeNode* root,string 
&leaf)
    {
        if(root->left==NULL && root->right==NULL)
        {
            leaf.push_back(root->val);
            return;
        }
        if(root->left) check(root->left,leaf);
        if(root->right) check(root->right,leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string leaf1="",leaf2="";
        check(root1,leaf1);
        check(root2,leaf2);
        if(leaf1 == leaf2) return true;
        return false;
    }
};
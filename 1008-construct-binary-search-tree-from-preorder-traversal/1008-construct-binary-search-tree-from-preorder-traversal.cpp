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
    TreeNode* insertIntoTree(TreeNode* &root,int data)
    {
        if(root == NULL)
        {
            TreeNode* node = new TreeNode(data);
            return node;
        }

        if(data < root->val)
            root->left = insertIntoTree(root->left,data);

        if(data > root->val)
            root->right = insertIntoTree(root->right,data);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(auto& num:preorder)
            root = insertIntoTree(root,num);
        return root;
    }
};
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
    vector<vector<int>> paths;
    void pathFind(TreeNode* root, int targetSum,vector<int> &ans)
    {
        if(root==NULL)
            return;
        if(root->val == targetSum && (root->left==NULL && root->right == NULL))
        {
            ans.push_back(root->val);
            paths.push_back(ans);
            ans.pop_back();
            return;
        }
        
        ans.push_back(root->val);
        pathFind(root->left,targetSum-(root->val),ans);
        ans.pop_back();
        ans.push_back(root->val);
        pathFind(root->right,targetSum-(root->val),ans);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        pathFind(root,targetSum,ans);
        return paths;
    }
};
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
    void getNums(TreeNode* root,vector<int>& nums,int num)
    {
        if(root==NULL)
        {
            return;
        }
        num = num* 10 + root->val;
        
        if(!root->left && !root->right)
        {
            nums.push_back(num);
            return;
        }
        
        getNums(root->left,nums,num);
        getNums(root->right,nums,num);
    }
    int sumNumbers(TreeNode* root) {
        int num = 0;
        vector<int> nums;
        getNums(root,nums,num);
        return accumulate(nums.begin(),nums.end(),0);
    }
};
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
    int ans = 0;
    int solve(TreeNode* root,bool direction)
    {
        if(!root)
            return -1;
        int left = solve(root->left,false);
        int right = solve(root->right,true);
        
        ans = max(ans,max(left+1,right+1));
        
        return direction ? left+1:right+1;
    }
    int longestZigZag(TreeNode* root) {
        solve(root,true);
        return ans;
    }
};
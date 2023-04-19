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
    void solve(TreeNode* root,bool direction,int length)
    {
        if(!root)
            return;
        ans = max(ans,length);
        if(direction) // go to left
        {
            solve(root->left,false,length+1);
            solve(root->right,true,1);
        }
        else // go to right
        {
            solve(root->right,true,length+1);
            solve(root->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root,true,0);
        return ans;
    }
};
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
    int counter = 1;
    int find(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int maxLeft = find(root->left);
        int maxRight = find(root->right);
        if(maxLeft==-1 || maxRight==-1)
            return -1;
        if(abs(maxLeft-maxRight) > 1)
            return -1;
        return max(maxLeft,maxRight)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return 1;
        if(find(root)==-1)
            return 0;
        return 1;
    }
};
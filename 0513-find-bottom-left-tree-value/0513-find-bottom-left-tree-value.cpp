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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        TreeNode* leftRoot = NULL;
        int maxLevel = -1;
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(level > maxLevel)
            {
                maxLevel = level;
                leftRoot = node;
            }
            
            if(node->left)
            {
                q.push({node->left,level+1});
            }
            if(node->right)
            {
                q.push({node->right,level+1});
            }
        }
        return leftRoot->val;
    }
};
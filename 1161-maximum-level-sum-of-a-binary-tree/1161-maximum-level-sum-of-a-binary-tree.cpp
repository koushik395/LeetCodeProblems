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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        int maxSum = INT_MIN;
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            int levelsum = 0;
            for(int i = 0;i < size;i++)
            {
                TreeNode* front = q.front();
                q.pop();
                
                levelsum += front->val;
                if(front -> left)
                {
                    q.push(front->left);
                }
                if(front-> right)
                {
                    q.push(front->right);
                }
            }
            if(levelsum > maxSum)
            {
                maxSum = levelsum;
                ans = level;
            }
        }
        return ans;
    }
};
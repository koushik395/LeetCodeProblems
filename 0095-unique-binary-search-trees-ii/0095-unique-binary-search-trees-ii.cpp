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
    vector<TreeNode*> generate(int start,int end)
    {
        if(start > end)
        {
            return {NULL};
        }
        vector<TreeNode*> ans;
        for(int i = start;i <= end;i++)
        {
            vector<TreeNode*> leftBST = generate(start,i-1);
            vector<TreeNode*> rightBST = generate(i+1,end);
            
            for(auto& left:leftBST)
            {
                for(auto& right:rightBST)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            } 
        }
        
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
};
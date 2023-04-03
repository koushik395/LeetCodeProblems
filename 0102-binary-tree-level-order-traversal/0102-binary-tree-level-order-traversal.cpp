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
    vector<vector<int>> ans;
    queue<TreeNode*> que;
    void levelorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        que.push(root);
        while (!que.empty())
        {
            int levelSize = que.size();
            vector<int> sub;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode* currNode = que.front();
                que.pop();

                sub.push_back(currNode->val);

                if (currNode->left != nullptr)
                    que.push(currNode->left);
                if (currNode->right != nullptr)
                    que.push(currNode->right);
            }
            ans.push_back(sub);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelorder(root);
        return ans;
    }
};
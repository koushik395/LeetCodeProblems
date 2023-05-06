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
    unordered_map<int,TreeNode*> mp;
    unordered_map<int,int> count;
    
    bool traverse(TreeNode* root,int min,int max)
    {
        if(root == NULL)
            return true;
        if(root->val <= min || root->val >= max)
            return false;
         
        if(root->left == root->right)
        {
            auto it = mp.find(root->val);
            if(it!=mp.end() && root != it->second)
            {
                root->left = it->second->left;
                root->right = it->second->right;
                mp.erase(it);
            }
        }
        
        return traverse(root->left,min,root->val) && traverse(root->right,root->val,max);
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for(auto& node:trees)
        {
            mp[node->val] = node;
            ++count[node->val];
            ++count[node->left?node->left->val:0];
            ++count[node->right?node->right->val:0];
        }
        
        for(auto& node:trees)
        {
            if(count[node->val] == 1)
            {
                return traverse(node,INT_MIN,INT_MAX) && mp.size()==1? node:NULL;
            }
        }
        return NULL;
    }
};
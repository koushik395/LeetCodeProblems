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
    TreeNode* findPredecessor(TreeNode* &current)
    {
        TreeNode* pred = current;
        pred = pred->left;
        while(pred->right!=NULL && pred->right!=current) // second condition for loop to successor
            pred = pred->right;

        return pred;
    }
    void MorrisTraversal(TreeNode* &root,unordered_map<int,int> &freq,int &mode)
    {
        TreeNode* current = root;
        while(current!=NULL)
        {
            if(current->left==NULL)
            {
                freq[current->val]++;
                if(freq[current->val] > mode) mode = freq[current->val];
                current = current->right;
            }
            else
            {
                TreeNode* pred = findPredecessor(current);
                if(pred->right == NULL)
                {
                    pred->right = current;
                    current = current->left;
                }
                else
                {
                    pred->right = NULL;
                    freq[current->val]++;
                    if(freq[current->val] > mode) mode = freq[current->val];
                    current = current -> right;
                }
            }
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int mode = 0;
        unordered_map<int,int> freq;
        MorrisTraversal(root,freq,mode);
        for(auto &it:freq)
        {
            if(it.second == mode)
                ans.push_back(it.first);
        }
        return ans;
        
    }
};
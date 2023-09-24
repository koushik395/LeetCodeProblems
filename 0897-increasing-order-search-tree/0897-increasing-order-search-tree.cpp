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
    
    void MorrisTraversal(TreeNode* &root,TreeNode* &newRoot)
    {
        TreeNode* current = root;
        TreeNode* tail = newRoot;
        while(current!=NULL)
        {
            if(current->left==NULL)
            {
                tail->right = current;
                tail = tail->right;
                current->left = NULL;
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
                    tail->right = current;
                    tail = tail->right;
                    current->left = NULL;
                    current = current -> right;
                }
            }
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = new TreeNode(0);
        MorrisTraversal(root,newRoot);
        return newRoot->right;
    }
};
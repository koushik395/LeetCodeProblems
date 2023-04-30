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
    TreeNode* minval(TreeNode* &root)
    {
        TreeNode* temp = root;
        while(temp->left!=NULL)
            temp = temp->left;

        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int data) {
        if(root==NULL)
		    return root;

        if(root->val == data)
        {
            //0 child
            if(!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            
            //2 child
            if(root->left && root->right)
            {
                int mini = minval(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right,mini);
                return root;
            }
            
            //1 child
            // left child
            if(root->left)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // right child
            if(root->right)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
        }
        else if(root->val > data)
            root->left = deleteNode(root->left,data);
        else
            root->right = deleteNode(root->right,data);

        return root;
    }
};
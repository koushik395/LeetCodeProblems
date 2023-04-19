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
    private:
    void findPos(vector<int> &inorder,unordered_map<int,int> &NodeToIndex)
    {
        for(int i =0;i<inorder.size();i++)
        {
            NodeToIndex[inorder[i]] = i;
        }
    }
public:
    int n,inStart,inEnd;
    unordered_map<int,int> NodeToIndex;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int inStart,int inEnd)
    {
        if(index >= n || inStart > inEnd)
            return NULL;
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position = NodeToIndex[element];
        
        root->left = solve(preorder,inorder,index,inStart,position-1);
        root->right = solve(preorder,inorder,index,position+1,inEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        n = preorder.size();
        findPos(inorder,NodeToIndex);
        TreeNode* ans = solve(preorder,inorder,preorderIndex,0,n-1);
        return ans;
    }
};
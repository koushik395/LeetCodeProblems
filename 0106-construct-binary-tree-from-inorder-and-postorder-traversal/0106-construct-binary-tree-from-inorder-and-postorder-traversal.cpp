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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int &index,int inStart,int inEnd)
    {
        if(index < 0 || inStart > inEnd)
            return NULL;
        
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = NodeToIndex[element];
        
        root->right = solve(postorder,inorder,index,position+1,inEnd);
        root->left = solve(postorder,inorder,index,inStart,position-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        int postorderIndex = n-1;
        findPos(inorder,NodeToIndex);
        TreeNode* ans = solve(postorder,inorder,postorderIndex,0,n-1);
        return ans;
    }
};
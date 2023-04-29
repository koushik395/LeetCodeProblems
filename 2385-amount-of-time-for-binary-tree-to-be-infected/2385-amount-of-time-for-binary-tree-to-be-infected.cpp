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
    void parent(TreeNode* root,int target,unordered_map<TreeNode*,TreeNode*> &parentNode,TreeNode* &res){
        if(root == NULL)
            return;
        if(root->val == target)
            res = root;
        if(root->left)
        {
            parentNode[root->left] = root;
            parent(root->left,target,parentNode,res);
        }
        if(root->right)
        {
            parentNode[root->right] = root;
            parent(root->right,target,parentNode,res);
        }
    }
    
    int burnTree(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentNode){
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        
        q.push(root);
        visited[root] = true;
        
        int ans = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for(int i=0;i<size;i++)
            {
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left])
                {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right])
                {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(parentNode[front] && !visited[parentNode[front]])
                {
                    flag = true;
                    q.push(parentNode[front]);
                    visited[parentNode[front]] = true;
                }
            }
            if(flag == true)
                ans++;
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* targetNode = NULL;
        unordered_map<TreeNode*,TreeNode*> parentNode;
        parentNode[root] = NULL;
        parent(root,start,parentNode,targetNode);
        
        return burnTree(targetNode,parentNode);
    }
};
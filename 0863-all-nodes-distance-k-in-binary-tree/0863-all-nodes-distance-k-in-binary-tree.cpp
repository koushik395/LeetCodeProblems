/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentNode)     {
        if(root == NULL)
            return;
        if(root->left)
        {
            parentNode[root->left] = root;
            parent(root->left,parentNode);
        }
        if(root->right)
        {
            parentNode[root->right] = root;
            parent(root->right,parentNode);
        }
    }
    
    void burnTree(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentNode,int k){
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        
        q.push(root);
        visited[root] = true;
        
        int dist = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for(int i=0;i<size;i++)
            {
                TreeNode* front = q.front();
                q.pop();
                
                if(dist == k) ans.push_back(front->val);
                
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
            {
                dist++;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentNode;
        parentNode[root] = NULL;
        parent(root,parentNode);
        
        burnTree(target,parentNode,k);
        return ans;
        
    }
};
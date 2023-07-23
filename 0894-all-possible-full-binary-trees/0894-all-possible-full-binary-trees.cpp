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
    unordered_map<int, vector<TreeNode*>> hashMap;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0)
        {
            return {};
        }
        if(n == 1)
        {
            return {new TreeNode()};
        }
        if(hashMap.count(n))
        {
            return hashMap[n];
        }
        vector<TreeNode*> result;
        for(int i=1; i<n; i+=2)
        {
            vector<TreeNode*> leftFBT = allPossibleFBT(i);
            vector<TreeNode*> rightFBT = allPossibleFBT(n-i-1);
            for(auto& L: leftFBT)
            {
                for(auto& R: rightFBT)
                {
                    TreeNode* root = new TreeNode();
                    root->left = L;
                    root->right = R;
                    result.push_back(root);
                }
            }
        }
        return hashMap[n] = result;
    }
};
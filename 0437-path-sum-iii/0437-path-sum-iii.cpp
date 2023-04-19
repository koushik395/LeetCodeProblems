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
    #define ll long long
    map<ll ,int> mp;
    int ans=0;
    void solve(TreeNode* root, int targetSum,ll currSum){
        if(root==NULL) return;
        
        currSum+=root->val;
        ans+=mp[currSum-targetSum];
        mp[currSum]++;
        
        solve(root->left , targetSum,currSum);
        solve(root->right , targetSum,currSum);
        
        mp[currSum]--;
        currSum-=root->val;

    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]++;
        ll currSum=0;
        solve(root,targetSum,currSum);
        return ans;
    }
};
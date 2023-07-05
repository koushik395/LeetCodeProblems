class Solution {
public:
    int n;
    int find(vector<int>&coins,int target,int i,vector<vector<int>> &dp)
    {
        if(i == 0)
        {
            if(target % coins[0] == 0) return target/coins[0];
            else return 1e9;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int nottake = find(coins,target,i-1,dp);
        
        int take = INT_MAX;
        if(coins[i] <= target) take = 1 + find(coins,target - coins[i],i,dp);
        
        return dp[i][target] = min(nottake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = find(coins,amount,n-1,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
class Solution {
public:
    int f(vector<int>& prices,int ind,int buy,vector<vector<int>> &dp)
    {
        if(ind == prices.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy)
        {
            // profit = (+Selling price)(-cost price)
            profit = max(-prices[ind] + f(prices,ind+1,0,dp) , 0 + f(prices,ind+1,1,dp));
        }
        else
        {
            profit = max(prices[ind] + f(prices,ind+1,1,dp), 0 + f(prices,ind+1,0,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(prices,0,1,dp);
    }
};
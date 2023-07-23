class Solution {
public:
    int f(vector<int>& prices,int ind,int buy,int cap,int n,vector<vector<vector<int>>> &dp)
    {
        if(cap == 0) return 0;
        if(ind == n) return 0;
        
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[ind] + f(prices,ind+1,0,cap,n,dp),0 + f(prices,ind+1,1,cap,n,dp));
        }
        else
        {
            profit = max(prices[ind] + f(prices,ind+1,1,cap-1,n,dp),0 + f(prices,ind+1,0,cap,n,dp));
        }
        
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,0,1,2,n,dp); //ind,buy,capacity
    }
};
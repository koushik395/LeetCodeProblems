class Solution {
public:
//     int f(vector<int>& prices,int ind,int buy,int cap,int n,vector<vector<vector<int>>> &dp)
//     {
//         if(cap == 0) return 0;
//         if(ind == n) return 0;
        
//         if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
//         int profit = 0;
//         if(buy)
//         {
//             profit = max(-prices[ind] + f(prices,ind+1,0,cap,n,dp),0 + f(prices,ind+1,1,cap,n,dp));
//         }
//         else
//         {
//             profit = max(prices[ind] + f(prices,ind+1,1,cap-1,n,dp),0 + f(prices,ind+1,0,cap,n,dp));
//         }
        
//         return dp[ind][buy][cap] = profit;
//     }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind = n-1;ind >= 0;ind--)
        {
            for(int buy = 0;buy <= 1;buy++)
            {
                for(int cap = 1;cap <= 2;cap++)
                {
                    if(buy)
                    {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],0 + dp[ind+1][1][cap]);
                    }
                    else
                    {
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1],0 + dp[ind+1][0][cap]);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};
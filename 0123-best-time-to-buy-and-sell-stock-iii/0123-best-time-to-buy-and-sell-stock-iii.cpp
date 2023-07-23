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
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int ind = n-1;ind >= 0;ind--)
        {
            for(int buy = 0;buy <= 1;buy++)
            {
                for(int cap = 1;cap <= 2;cap++)
                {
                    if(buy)
                    {
                        curr[buy][cap] = max(-prices[ind] + after[0][cap],0 + after[1][cap]);
                    }
                    else
                    {
                        curr[buy][cap] = max(prices[ind] + after[1][cap-1],0 + after[0][cap]);
                    }
                }
            }
            after = curr;
        }
        
        return after[1][2];
    }
};
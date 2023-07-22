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
        int n = prices.size();
        vector<int> curr(2,0),next(2,0);
        next[0] = next[1] = 0;
        
        for(int ind = n-1;ind >= 0;ind--)
        {
            for(int buy = 0;buy <= 1;buy++)
            {
                 int profit = 0;
                if(buy)
                {
                    // profit = (+Selling price)(-cost price)
                    profit = max(-prices[ind] + next[0] , 0 + next[1]);
                }
                else
                {
                    profit = max(prices[ind] + next[1], 0 + next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};
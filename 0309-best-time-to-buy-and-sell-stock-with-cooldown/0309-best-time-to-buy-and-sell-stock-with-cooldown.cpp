class Solution {
public:
//     int f(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp)
//     {
//         if(ind >= prices.size()) return 0;
        
//         if(dp[ind][buy] != -1) return dp[ind][buy];
//         int profit = 0;
//         if(buy)
//         {
//             profit =  max(-prices[ind] + f(ind + 1,0,prices,dp),0 + f(ind + 1,1,prices,dp));
//         }
//         else
//         {
//             profit =  max(prices[ind] + f(ind + 2,1,prices,dp),0 + f(ind+1,0,prices,dp));
//         }
        
//         return dp[ind][buy] = profit;
//     }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front2(2,0),front1(2,0),curr(2,0);
        for(int ind = n-1;ind>=0;ind--)
        {
            curr[1] =  max(-prices[ind] + front1[0],0 + front1[1]);

            curr[0] =  max(prices[ind] + front2[1],0 + front1[0]);
            
            front2 = front1;
            front1 = curr;
        }
        return front1[1];
    }
};
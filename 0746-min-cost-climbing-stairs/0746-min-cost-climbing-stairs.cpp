class Solution {
public:
    int f(int ind,vector<int>& heights,vector<int> &dp)
    {
        if(ind == 0 || ind == 1) return heights[ind];

        if(dp[ind] != -1) return dp[ind];
        int left = f(ind-1,heights,dp) + heights[ind];

        int right=INT_MAX;
        if(ind > 1)
        {
            right = f(ind-2,heights,dp) + heights[ind];
        }

        return dp[ind] = min(left,right);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(f(n-1,cost,dp),f(n-2,cost,dp));
    }
};
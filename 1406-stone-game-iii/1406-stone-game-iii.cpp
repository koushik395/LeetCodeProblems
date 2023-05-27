class Solution {
public:
    int helper(vector<int> &dp,vector<int> &stoneValue,int i)
    {
        int n = stoneValue.size();
        if(i >= n) return 0;
        
        if(dp[i]!=INT_MAX) return dp[i];
        
        int takeone = stoneValue[i] - helper(dp,stoneValue,i+1);
        
        int taketwo = INT_MIN;
        if(i+1 < n) taketwo = stoneValue[i] + stoneValue[i+1] - helper(dp,stoneValue,i+2);
        
        int takethree = INT_MIN;
        if(i+2 < n) takethree = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - helper(dp,stoneValue,i+3);
        
        return dp[i] = max({takeone,taketwo,takethree});
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(),INT_MAX);
        int value = helper(dp,stoneValue,0);
        if(value > 0)
            return "Alice";
        return value < 0 ? "Bob":"Tie";
    }
};
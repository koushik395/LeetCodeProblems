class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(3,0);
        
        for(int i = n-1; i>= 0;i--)
        {
            int takeone = stoneValue[i] - dp[(i+1)%3];
        
            int taketwo = INT_MIN;
            if(i+1 < n) taketwo = stoneValue[i] + stoneValue[i+1] - dp[(i+2)%3];

            int takethree = INT_MIN;
            if(i+2 < n) takethree = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[(i+3)%3];

            dp[i%3] = max({takeone,taketwo,takethree});    
        }
        
        int value = dp[0];
        if(value > 0)
            return "Alice";
        return value < 0 ? "Bob":"Tie";
    }
};
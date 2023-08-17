class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        int moves = 0;
        
        while(dp[moves][k] < n)
        {
            moves++;
            for(int i = 1;i <= k;i++)
            {
                dp[moves][i] = dp[moves-1][i-1] + dp[moves-1][i] + 1;
            }
        }
        return moves;  
    }
};
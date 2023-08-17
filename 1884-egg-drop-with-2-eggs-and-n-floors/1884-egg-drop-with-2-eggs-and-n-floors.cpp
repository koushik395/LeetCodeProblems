class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        int moves = 0;
        
        while(dp[moves][2] < n)
        {
            moves++;
            for(int i = 1;i <= 2;i++)
            {
                dp[moves][i] = dp[moves-1][i-1] + dp[moves-1][i] + 1;
            }
        }
        return moves;  
    }
};
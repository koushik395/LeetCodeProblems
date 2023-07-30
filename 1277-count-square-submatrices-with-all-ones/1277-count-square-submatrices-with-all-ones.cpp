class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int tot = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(arr[i][j] == 1)
                {
                    if(i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                      dp[i][j] =
                          1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    }
                    tot += dp[i][j];
                }
            }
        }
        return tot;
    }
};
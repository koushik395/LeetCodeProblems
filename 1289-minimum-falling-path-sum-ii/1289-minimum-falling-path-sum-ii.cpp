class Solution {
public:
    int find(int i,int j,vector<vector<int>>& matrix,int n,int m,vector<vector<int>> &dp)
    {
        if(j < 0 || j >= m) return 1e9;
        if(i == 0) return matrix[0][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = 1e9;
        for(int col = 0;col < m;col++)
        {
            if(col != j)
            mini = min(mini,matrix[i][j] + find(i-1,col,matrix,n,m,dp));
        }

        return dp[i][j] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int mini = 1e9;
        for(int i = 0;i < m;i++)
        {
            mini = min(mini,find(n-1,i,grid,n,m,dp));
        }
        return mini;
    }
};
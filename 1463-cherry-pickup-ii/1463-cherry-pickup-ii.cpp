class Solution {
public:
//     int find(int i,int j1,int j2,vector<vector<int>>& grid,int row,int col,vector<vector<vector<int>>> &dp)
//     {
//         if(j1 < 0 || j1>=col || j2 < 0 || j2 >=col)
//         {
//             return -1e9;
//         }
        
//         if(i == row-1)
//         {
//             if(j1 == j2) return grid[i][j1];
//             else return grid[i][j1] + grid[i][j2];
//         }
        
//         if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
//         int maxi = -1;
//         for(int n = -1;n <= 1;n++)
//         {
//             for(int m = -1;m <= 1;m++)
//             {
//                 if(j1 == j2) maxi = max(maxi,grid[i][j1] +find(i+1,j1+n,j2+m,grid,row,col,dp));
//                 else maxi = max(maxi,grid[i][j1] + grid[i][j2]+find(i+1,j1+n,j2+m,grid,row,col,dp));
//             }
//         }
        
//         return dp[i][j1][j2] = maxi;
//     }
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));
        
        for(int j1 = 0;j1 < col;j1++)
        {
            for(int j2 = 0;j2 < col;j2++)
            {
                if(j1 == j2) dp[row-1][j1][j2] = grid[row-1][j1];
                else dp[row-1][j1][j2] = grid[row-1][j1] + grid[row-1][j2];
            }
        }
        
        for(int i = row-2;i >= 0;i--)
        {
            for(int j1 = 0;j1 < col;j1++)
            {
                for(int j2 = 0;j2 < col;j2++)
                {
                    int maxi = -1;
                    for(int n = -1;n <= 1;n++)
                    {
                        for(int m = -1;m <= 1;m++)
                        {
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            
                            if(j1+n >= 0 && j1+n < col && j2+m >=0 && j2+m < col)
                            {
                                value += dp[i+1][j1+n][j2+m];
                            }
                            else
                            {
                                value += -1e9;
                            }
                            maxi = max(maxi,value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        
        return dp[0][0][col-1];
    }
};
class Solution {
public:
//     int GeneratePaths(int m, int n, int x, int y, vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid) {
//     if (x == m - 1 && y == n - 1) {
//         return 1;
//     }

//     if (dp[x][y] != -1) {
//         return dp[x][y];
//     }

//     auto isSafe = [&](int& x, int& y) {
//         return x >= 0 && x < m && y >= 0 && y < n && !obstacleGrid[x][y];
//     };

//     // go down
//     int downPaths = 0;
//     int newx = x + 1;
//     int newy = y;
//     if (isSafe(newx, newy)) {
//         downPaths = GeneratePaths(m, n, newx, newy, dp,obstacleGrid);
//     }

//     // go right
//     int rightPaths = 0;
//     newx = x;
//     newy = y + 1;
//     if (isSafe(newx, newy)) {
//         rightPaths = GeneratePaths(m, n, newx, newy, dp,obstacleGrid);
//     }
//     dp[x][y] = downPaths + rightPaths;
//     return dp[x][y];
// }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else
                {
                    int up = 0,left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
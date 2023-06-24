class Solution {
public:
//     int GeneratePaths(int m, int n, int x, int y, vector<vector<int>>& dp) {
//         if (x == m - 1 && y == n - 1) {
//             return 1;
//         }

//         if (dp[x][y] != -1) {
//             return dp[x][y];
//         }

//         auto isSafe = [&](int& x, int& y) {
//             return x >= 0 && x < m && y >= 0 && y < n;
//         };

//         // go down
//         int downPaths = 0;
//         int newx = x + 1;
//         int newy = y;
//         if (isSafe(newx, newy)) {
//             downPaths = GeneratePaths(m, n, newx, newy, dp);
//         }

//         // go right
//         int rightPaths = 0;
//         newx = x;
//         newy = y + 1;
//         if (isSafe(newx, newy)) {
//             rightPaths = GeneratePaths(m, n, newx, newy, dp);
//         }

//         dp[x][y] = downPaths + rightPaths;
//         return dp[x][y];
//     }
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i = 0;i < m;i++)
        {
            vector<int> curr(n,0);
            for(int j = 0;j < n;j++)
            {
                if(i == 0 && j == 0) curr[j] = 1;
                else
                {
                    int up = 0,left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up+left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
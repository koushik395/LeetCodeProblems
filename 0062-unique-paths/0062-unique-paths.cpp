class Solution {
public:
    int ans = 0;
   
    int GeneratePaths(int m, int n, int x, int y, vector<vector<int>>& dp) {
        if (x == m - 1 && y == n - 1) {
            ans++;
            return 1; // Changed to 1, indicating a successful path
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        auto isSafe = [&](int& x, int& y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        // go down
        int downPaths = 0;
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy)) {
            downPaths = GeneratePaths(m, n, newx, newy, dp);
        }

        // go right
        int rightPaths = 0;
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy)) {
            rightPaths = GeneratePaths(m, n, newx, newy, dp);
        }

        dp[x][y] = downPaths + rightPaths; // Store the total number of paths in dp table
        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int x = 0,y= 0;
        return GeneratePaths(m,n,x,y,dp);
    }
};
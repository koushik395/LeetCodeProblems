class Solution {
public:
    int cherryPickupRecursive(vector<vector<vector<vector<int>>>> 
            &dp,vector<vector<int>>& grid, int row1, int col1, int row2, int col2) {
        
    int n = grid.size();
    if (row1 >= n || col1 >= n || row2 >= n || col2 >= n || grid[row1][col1] == -1 || grid[row2][col2] == -1) {
        return INT_MIN;
    }

    if ((row1 == n - 1 && col1 == n - 1) || (row2 == n-1 && col2 == n-1)) {
        return grid[row1][col1];
    }
    
    int cherries = (row1 == row2 && col1 == col2) ? grid[row1][col1] : grid[row1][col1] + grid[row2][col2];
    
    if(dp[row1][col1][row2][col2] != -1) return dp[row1][col1][row2][col2];
    int maxCherries = max({
        cherryPickupRecursive(dp,grid, row1 + 1, col1, row2 + 1, col2),
        cherryPickupRecursive(dp,grid, row1 + 1, col1, row2, col2 + 1),  
        cherryPickupRecursive(dp,grid, row1, col1 + 1, row2 + 1, col2),
        cherryPickupRecursive(dp,grid, row1, col1 + 1, row2, col2 + 1)
    });
    
    return dp[row1][col1][row2][col2] = cherries + maxCherries;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
        return max(0, cherryPickupRecursive(dp, grid, 0, 0, 0, 0));
    }
};
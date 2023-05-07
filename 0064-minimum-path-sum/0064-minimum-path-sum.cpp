class Solution {
public:
    int solve(vector<vector<int>> &memo,vector<vector<int>>& grid,int n,int m)
    {
        if(n==0 && m==0)
            return grid[0][0];
        if(n < 0 || m < 0)
            return 1e9;
        if(memo[n][m] != -1)
            return memo[n][m];
        
        int up = grid[n][m] + solve(memo,grid,n-1,m);
        int left = grid[n][m] + solve(memo,grid,n,m-1);
        return memo[n][m] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return solve(memo,grid,n-1,m-1);
    }
};
class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
    int dfs(int x,int y,vector<vector<int>> &dp,vector<vector<int>>& grid,int &rows,int &cols)
    {
        if(dp[x][y]!=-1) return dp[x][y];
        
        auto isSafe = [&](const int &newx,const int &newy)
        {
            return (newx >= 0 && newx <rows && newy >=0 && newy< cols 
            && (grid[newx][newy] > grid[x][y]));
        };
        int ans = 1;
        
        for(auto& it:dir)
        {
            int newx = x + it[0];
            int newy = y + it[1];
            
            if(isSafe(newx,newy))
            {
                ans = max(ans,1+dfs(newx,newy,dp,grid,rows,cols));
            }
        }
        return dp[x][y] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int maxi = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                maxi = max(maxi,dfs(i,j,dp,grid,n,m));
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int mini=INT_MAX;
    
    int solve(vector<vector<int>>&tri, int col, int row, vector<vector<int>>& dp)
    {
        if(col < 0 || col > row) return 1e9;
        if(col==0 && row==0)
        {
            return tri[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        
        int up=tri[row][col]+solve(tri,col,row-1,dp);
        int left = tri[row][col]+solve(tri,col-1,row-1,dp);
        
        return dp[row][col]= min(left,up);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m,vector(m,-1));
        for(int i=0;i<m;++i)
        {
            mini=min(mini,solve(triangle,i,m-1,dp));
        }
        return mini;
    }
};
class Solution {
public:
//     int find(int i,int j,vector<vector<int>>& matrix,int n,int m,vector<vector<int>> &dp)
//     {
//         if(j < 0 || j >= m) return 1e9;
//         if(i == 0) return matrix[0][j];
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int straight = matrix[i][j] + find(i-1,j,matrix,n,m,dp);
//         int leftdiag = matrix[i][j] + find(i-1,j-1,matrix,n,m,dp);
//         int rightdia = matrix[i][j] + find(i-1,j+1,matrix,n,m,dp);
        
//         return dp[i][j] = min({straight,leftdiag,rightdia});
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<int> prev(n,0),curr(n,0);
        
        for(int j = 0;j < m;j++)
        {
            prev[j] = matrix[0][j];
        }
        
        for(int i = 1; i < n;i++)
        {
            for(int j = 0; j< m;j++)
            {
                int straight = matrix[i][j] + prev[j];
                int leftdiag = matrix[i][j];
                if(j-1 >= 0) leftdiag += prev[j-1];
                else leftdiag += 1e9;
                
                int rightdia = matrix[i][j];
                if(j+1 < m) rightdia += prev[j+1];
                else rightdia += 1e9;
                
                curr[j]  = min({straight,leftdiag,rightdia});          
            }
            prev = curr;
        }
        int mini = prev[0];
        for(int j = 1; j < m;j++)
        {
            mini = min(mini,prev[j]);
        }
        
        return mini;
    }
};
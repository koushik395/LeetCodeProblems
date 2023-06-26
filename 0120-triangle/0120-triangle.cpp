class Solution {
public:
//     int find(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>> &dp)
//     {
//     	if(i == n-1)
//     	{
//     		return triangle[n-1][j];
//     	}
    
//     	if(dp[i][j]!=-1) return dp[i][j];
//     	int down = triangle[i][j] + find(i+1,j,n,triangle,dp);
//     	int diag = triangle[i][j] + find(i+1,j+1,n,triangle,dp);
    
//     	return dp[i][j] = min(down,diag);
//     }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> next(n,0);
	    for(int i = 0; i < n;i++)
        {
            next[i] = triangle[n-1][i];
        }
        
        for(int i = n-2;i >= 0;i--)
        {
            vector<int> curr(n,0);
            for(int j = 0;j <= i;j++)
            {
                int d = triangle[i][j] + next[j];
                int dia = triangle[i][j] + next[j+1];
                curr[j] = min(d,dia);
            }
            next = curr;
        }
        return next[0];
    }
};
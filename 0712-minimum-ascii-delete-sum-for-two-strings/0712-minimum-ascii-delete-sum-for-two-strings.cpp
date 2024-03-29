class Solution {
public:
    // int n, m;
//     int solve(string& s1, string& s2, int i, int j,vector<vector<int>> &dp)
//     {
//         if(i == 0 && j == 0)
//         {
//             return 0;
//         }
//         if(i == 0) // j is still there so delete them.
//         {
//             int cost = 0;
//             for(int k=1; k<=j; k++)
//             {
//                 cost += (int)s2[k-1];
//             }
//             return cost;
//         }
//         if(j == 0) // i is still there so delete them.
//         {
//             int cost = 0;
//             for(int k=1; k<=i; k++)
//             {
//                 cost += (int)s1[k-1];
//             }
//             return cost;
//         }
        
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s1[i-1] == s2[j-1])
//         {
//             return dp[i][j] = solve(s1, s2, i-1, j-1,dp);
//         }
//         int delstr1 = (int)s1[i-1] + solve(s1, s2, i-1, j,dp);
//         int delstr2 = (int)s2[j-1] + solve(s1, s2, i, j-1,dp);
//         return dp[i][j] = min(delstr1, delstr2);
//     }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<int> curr(m+1,0),prev(m+1,0);
        
        for(int j=1; j<=m; j++)
        {
            prev[j] = prev[j-1] + (int)s2[j-1];
        }

        for(int i = 1;i <= n;i++)
        {
            curr[0] = prev[0] + (int)s1[i-1];
            for(int j = 1;j <= m;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    curr[j] = prev[j-1];
                }
                else
                {
                    int delstr1 = (int)s1[i-1] + prev[j];
                    int delstr2 = (int)s2[j-1] + curr[j-1];
                    curr[j] = min(delstr1, delstr2);   
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
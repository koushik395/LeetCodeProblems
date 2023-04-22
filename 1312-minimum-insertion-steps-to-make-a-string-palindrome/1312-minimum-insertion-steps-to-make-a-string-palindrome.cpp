class Solution {
public:
    int lcs(string text1, string text2,int m,int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] =0;
                else if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];   
                }
                else
                {
                    int a = dp[i-1][j];
                    int b = dp[i][j-1];
                    dp[i][j] = max(a,b);
                }
            }
        }
        return dp[m][n];
    }
    int minInsertions(string s) {
        int m = s.length();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s.length() - lcs(s,s2,m,m);
    }
};
class Solution {
public:
    string s="";
    void lcs(string text1, string text2,int m,int n)
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

        int i = m,j = n;
        while(i > 0 && j > 0)
        {
            if(text1[i-1] == text2[j-1])
            {
                s = text1[i-1] + s;
                i--, j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                s = text1[i-1] + s;
                i--;
            }
            else
            {
                s = text2[j-1] + s;
                j--;
            }
        }
        while(i > 0) s = text1[i-1] + s, i--;
        while(j > 0) s = text2[j-1] + s, j--;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        lcs(str1,str2,m,n);
        return s;
    }
};
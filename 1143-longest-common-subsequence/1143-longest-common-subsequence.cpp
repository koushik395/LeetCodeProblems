class Solution {
public:
    int lcs(string text1, string text2,int m,int n)
    {
        vector<int> prev(m+1,0),curr(n+1,0);
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    curr[j] =0;
                else if(text1[i-1] == text2[j-1])
                    curr[j] = 1+ prev[j-1];
                else
                {
                    int a = prev[j];
                    int b = curr[j-1];
                    curr[j] = max(a,b);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        return lcs(text1,text2,m,n);
    }
};
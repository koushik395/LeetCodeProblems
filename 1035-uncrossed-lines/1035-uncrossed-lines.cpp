class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] =0;
                else if(nums1[i-1] == nums2[j-1])
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
};
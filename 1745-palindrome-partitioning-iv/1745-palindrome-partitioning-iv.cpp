class Solution {
public:
    int n;
    bool isPalindrome(string& s,int l,int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    bool f(int i,int part,string& s,vector<vector<int>> &dp)
    {
        if(i == n) return 0;

        if(part == 0)
        {
            return isPalindrome(s,i,n-1);
        }

        if(dp[i][part] != -1) return dp[i][part];

        bool possible = false;
        for(int k = i;k < n-1;k++)
        {
            possible = possible || (isPalindrome(s,i,k) && f(k+1,part-1,s,dp));
        }
        return dp[i][part] = possible;
    }
    bool checkPartitioning(string s) {
        n = s.length();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return f(0,2,s,dp);
    }
};
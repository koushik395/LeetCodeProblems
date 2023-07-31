class Solution {
public:
    int n;
    int cost(string& s,int l,int r)
    {
        int cost = 0;
        while(l < r)
        {
            if(s[l++] != s[r--]) cost++;
        }
        return cost;
    }
    int f(int i,int part,string& s,vector<vector<int>> &dp)
    {
        if(i == n) return 0;
        
        if(part == 0)
        {
            return cost(s,i,n-1);
        }
        
        if(dp[i][part] != -1) return dp[i][part];
        int mincost = 1e9;
        for(int k = i;k < n-1;k++)
        {
            int currcost = cost(s,i,k) + f(k+1,part-1,s,dp);
            mincost = min(mincost,currcost);
        }
        return dp[i][part] = mincost;
    }
    int palindromePartition(string s, int k) {
        n = s.length();
        vector<vector<int>> dp(n,vector<int>(k,-1));
        return f(0,k-1,s,dp);
    }
};
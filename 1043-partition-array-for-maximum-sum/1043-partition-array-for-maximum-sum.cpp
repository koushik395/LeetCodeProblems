class Solution {
public:
    int f(int i,int n,int k,vector<int>& arr,vector<int> &dp)
    {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int len = 0,maxnum = -1,maxAns = -1;
        for(int ind = i;ind < min(n,i+k);ind++)
        {
            len++;
            maxnum = max(maxnum,arr[ind]);
            int sum = len * maxnum + f(ind+1,n,k,arr,dp);
            maxAns = max(maxAns,sum);
        }
        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,n,k,arr,dp);
    }
};
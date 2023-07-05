class Solution {
public:
    int findWays(vector<int> &num, int k){
        int n = num.size();

        vector<vector<int>> dp(n,vector<int>(k+1,0));

        if(num[0] == 0) dp[0][0]  = 2;
        else dp[0][0] = 1;

        if(num[0]!=0 && num[0]<=k)
            dp[0][num[0]] = 1;

        for(int ind = 1; ind<n; ind++){
            for(int target= 0; target<=k; target++){

                int notTaken = dp[ind-1][target];

                int taken = 0;
                    if(num[ind]<=target)
                        taken = dp[ind-1][target-num[ind]];

                dp[ind][target]= (notTaken + taken);
            }
        }

        return dp[n-1][k];
    }
    int findTargetSumWays(vector<int>& arr, int d) {
        int tot = accumulate(arr.begin(),arr.end(),0);
        if(tot- d < 0 || (tot-d)%2) return 0;

        return findWays(arr, (tot-d)/2);
    }
};
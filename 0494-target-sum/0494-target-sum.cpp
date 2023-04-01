class Solution {
public:
    int isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0 && j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = 0;
            else
            {
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                {
                    int take = dp[i-1][j-arr[i-1]];
                    int nottake = dp[i-1][j];
                    dp[i][j] = (take+nottake);   
                }
            }
            
        }
    }
    return dp[n][sum];
}

    int findTargetSumWays(vector<int>& arr, int d) {
        if(d<0)
            d*=-1;
        int sum = accumulate(arr.begin(),arr.end(),0);
    	if((sum+d) & 1)
    		return 0;
    	int reqsum = (sum+d)>>1;
        return isSubsetSum(arr,reqsum);
    }
};
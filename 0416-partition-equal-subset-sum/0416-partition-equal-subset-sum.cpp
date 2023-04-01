class Solution {
public:
    bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0 && j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = 0;
            else if(j==0)
                dp[i][j] = 1;
            else
            {
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                {
                    int take = dp[i-1][j-arr[i-1]];
                    int nottake = dp[i-1][j];
                    dp[i][j] = take||nottake;   
                }
            }
            
        }
    }
    return dp[n][sum];
}
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum & 1)
            return false;
        sum >>= 1;
        int n = nums.size();
        return isSubsetSum(nums,sum);
    }
};
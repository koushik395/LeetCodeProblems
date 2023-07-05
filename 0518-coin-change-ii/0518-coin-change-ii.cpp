class Solution {
public:
    int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

        if(ind == 0){
            if(T%arr[0] == 0) return 1;
            else return 0;
        }

        if(dp[ind][T]!=-1)
            return dp[ind][T];

        int notTaken = minimumElementsUtil(arr,ind-1,T,dp);

        int taken = 0;
        if(arr[ind] <= T)
            taken = minimumElementsUtil(arr,ind,T-arr[ind],dp);

        return dp[ind][T] = notTaken + taken;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= minimumElementsUtil(coins,n-1,amount,dp);
        
        return ans;
    }
};
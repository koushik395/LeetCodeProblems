class Solution {
public:
//     int n;
//     int find(vector<int>&coins,int target,int i,vector<vector<int>> &dp)
//     {
//         if(i == 0)
//         {
//             if(target % coins[0] == 0) return target/coins[0];
//             else return 1e9;
//         }
//         if(dp[i][target] != -1) return dp[i][target];
//         int nottake = find(coins,target,i-1,dp);
        
//         int take = INT_MAX;
//         if(coins[i] <= target) take = 1 + find(coins,target - coins[i],i,dp);
        
//         return dp[i][target] = min(nottake,take);
//     }
    int coinChange(vector<int>& arr, int T) {
    
        int n= arr.size();

        vector<int> prev(T+1,0), cur(T+1,0);

        for(int i=0; i<=T; i++){
            if(i%arr[0] == 0)  
                prev[i] = i/arr[0];
            else prev[i] = 1e9;
        }

        for(int ind = 1; ind<n; ind++){
            for(int target = 0; target<=T; target++){

                int notTake = 0 + prev[target];
                int take = 1e9;
                if(arr[ind]<=target)
                    take = 1 + cur[target - arr[ind]];

                 cur[target] = min(notTake, take);
            }
            prev = cur;
        }

        int ans = prev[T];
        if(ans >=1e9) return -1;
        return ans;
    }
};
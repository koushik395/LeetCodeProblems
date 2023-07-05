class Solution {
public:
//     int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

//         if(ind == 0){
//             if(T%arr[0] == 0) return 1;
//             else return 0;
//         }

//         if(dp[ind][T]!=-1)
//             return dp[ind][T];

//         int notTaken = minimumElementsUtil(arr,ind-1,T,dp);

//         int taken = 0;
//         if(arr[ind] <= T)
//             taken = minimumElementsUtil(arr,ind,T-arr[ind],dp);

//         return dp[ind][T] = notTaken + taken;
// }
    int change(int T, vector<int>& arr) {
        int n= arr.size();
    
        vector<int> prev(T+1,0), cur(T+1,0);

        for(int i=0; i<=T; i++){
            if(i%arr[0] == 0)  
                prev[i] = 1;
            else prev[i] = 0;
        }

        for(int ind = 1; ind<n; ind++){
            for(int target = 0; target<=T; target++){

                int notTake = 0 + prev[target];
                int take = 0;
                if(arr[ind]<=target)
                    take = cur[target - arr[ind]];

                 cur[target] = take + notTake;
            }
            prev = cur;
        }

        int ans = prev[T];
        return ans;
    }
};
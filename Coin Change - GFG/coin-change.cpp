//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long f(int coins[],int target, int i,vector<vector<long long>>& dp)
    {
        if(i == 0)
        {
            return target%coins[0] == 0;
        }
        
        
        if(dp[i][target]!=-1)
           return dp[i][target];
        
        long long nottake=f(coins,target,i-1,dp);
        
        long long take=0;
        if(coins[i]<=target)
            take=f(coins,target-coins[i],i,dp);
        
        long long ans=take+nottake;
        
        return dp[i][target] = ans;
   }
    long long int count(int coins[], int N, int sum) 
    {
         vector<vector<long long>> dp(N,vector<long long>(sum+1,-1));
        return f(coins,sum,N-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
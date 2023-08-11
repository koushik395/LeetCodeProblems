//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int ind,int tar,int coins[],vector<vector<long long>> &dp)
    {
        if(ind == 0)
        {
            return (tar%coins[ind] == 0);
        }
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        long long nottake = solve(ind-1,tar,coins,dp);
        
        long long take = 0;
        if(coins[ind] <= tar)
        {
            take = solve(ind,tar-coins[ind],coins,dp);
        }
        
        return dp[ind][tar] = take + nottake;
    }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>> dp(N,vector<long long>(sum+1,-1));
        return solve(N-1,sum,coins,dp);
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
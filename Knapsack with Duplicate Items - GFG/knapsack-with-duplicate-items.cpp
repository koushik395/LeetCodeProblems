//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int index,int N, int W, int val[], int wt[],vector<vector<int>>&dp)
    {
        if(index>=N)
        {
            return 0;
        }
        
        if(dp[index][W]!=-1)
        {
            return  dp[index][W];
        }
        
        int take = INT_MIN;
        
        if(W-wt[index]>=0)
        {
            take = val[index]+solve(index,N,W-wt[index],val,wt,dp);
        }
        
        int nottake = solve(index+1,N,W,val,wt,dp);
        
        return dp[index][W] = max(take,nottake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        return solve(0,N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
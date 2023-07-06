//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int ind,int w,int profit[],int weight[],vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            return (w/weight[0]) * profit[0];
        }
    
        if(dp[ind][w]!=-1) return dp[ind][w];
    
        int nottake = 0 + f(ind-1,w,profit,weight,dp);
        int take = INT_MIN;
        if(weight[ind] <= w)
        {
            take = profit[ind] + f(ind,w-weight[ind],profit,weight,dp);
        }
    
        return dp[ind][w] = max(take,nottake);
    }
    int knapSack(int n, int w, int profit[], int weight[])
    {
        vector<int> prev(w+1,0);
        for(int W = 0 ; W <= w;W++)
        {
            prev[W] = (W/weight[0]) * profit[0];
        }
        
        for(int ind = 1;ind < n;ind++)
        {
            for(int W=0; W <= w;W++)
            {
                int nottake = 0 + prev[W];
                int take = INT_MIN;
                if(weight[ind] <= W)
                {
                    take = profit[ind] + prev[W-weight[ind]];
                }
                
                prev[W] = max(take,nottake);
            }
        }
        return prev[w];
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
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int f(int i,int n,int k,vector<int>& arr,vector<int> &dp)
    {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int len = 0,maxnum = -1,maxAns = -1;
        for(int ind = i;ind < min(n,i+k);ind++)
        {
            len++;
            maxnum = max(maxnum,arr[ind]);
            int sum = len * maxnum + f(ind+1,n,k,arr,dp);
            maxAns = max(maxAns,sum);
        }
        return dp[i] = maxAns;
    }
    int solve(int n, int k, vector<int>& arr){
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int i = n-1;i >= 0;i--)
        {
            int len = 0,maxnum = -1,maxAns = -1;
            for(int ind = i;ind < min(n,i+k);ind++)
            {
                len++;
                maxnum = max(maxnum,arr[ind]);
                int sum = len * maxnum + dp[ind+1];
                maxAns = max(maxAns,sum);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
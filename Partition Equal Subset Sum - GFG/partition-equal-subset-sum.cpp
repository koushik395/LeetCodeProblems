//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0;i < N;i++)
        {
            sum += arr[i];
        }
        if(sum & 1) return false;
        vector<vector<bool>> dp(N,vector<bool>((sum/2)+1,false));
        
        for(int i=0; i<N; i++){
            dp[i][0] = true;
        }
        
        if(arr[0] <= sum/2)
        {
            dp[0][arr[0]] = true;
        }
        
        for(int i = 1;i < N;i++)
        {
            for(int tar = 1;tar <= (sum/2);tar++)
            {
                bool nottake = dp[i-1][tar];
        
                bool take = false;
                if(arr[i] <= tar)
                {
                    take = dp[i-1][tar-arr[i]];
                }
                dp[i][tar] = nottake | take;
            }
        }
        
        return dp[N-1][sum/2];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
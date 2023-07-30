//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    int f(int i,int j,int isTrue,string &exp,vector<vector<vector<int>>> &dp)
    {
        if(i > j) return 0;
        if(i == j)
        {
            if(isTrue) return exp[i] == 'T';
            else return exp[i] == 'F';
        }
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
        int ways = 0;
        for(int k = i+1;k <= j-1;k+=2)
        {
            int LeftTrue = f(i,k-1,1,exp,dp)%mod;
            int LeftFalse = f(i,k-1,0,exp,dp)%mod;
            int RightTrue = f(k+1,j,1,exp,dp)%mod;
            int RightFalse = f(k+1,j,0,exp,dp)%mod;
    
            if(exp[k] == '&')
            {
                if(isTrue) ways = (ways + (RightTrue * LeftTrue) % mod)%mod;
                else ways = (ways + (RightTrue * LeftFalse)%mod + 
                (LeftTrue * RightFalse)%mod + (LeftFalse * RightFalse)%mod)%mod;
            }
            else if(exp[k] == '|')
            {
                if(isTrue)  ways = (ways + (RightTrue * LeftFalse)%mod + 
                (LeftTrue * RightFalse)%mod + (LeftTrue * RightTrue)%mod)%mod;
                else ways = (ways + (LeftFalse * RightFalse)%mod)%mod;
            }
            else
            {
                if(isTrue)  ways = (ways + (RightTrue * LeftFalse)%mod + 
                (LeftTrue * RightFalse)%mod)%mod;
                else ways = (ways + (LeftFalse * RightFalse)%mod 
                + (LeftTrue * RightTrue)%mod)%mod;
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(int n, string exp){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,1,exp,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
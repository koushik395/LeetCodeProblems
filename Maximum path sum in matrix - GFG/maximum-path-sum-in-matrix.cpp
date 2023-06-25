//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int find(int i,int j,vector<vector<int>>& matrix,int n,int m,vector<vector<int>> &dp)
    {
        if(j < 0 || j >= m) return -1e9;
        if(i == 0) return matrix[0][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int straight = matrix[i][j] + find(i-1,j,matrix,n,m,dp);
        int leftdiag = matrix[i][j] + find(i-1,j-1,matrix,n,m,dp);
        int rightdia = matrix[i][j] + find(i-1,j+1,matrix,n,m,dp);
        
        return dp[i][j] = max({straight,leftdiag,rightdia});
    }
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int maxi = -1e9;
        for(int i = 0; i < n;i++)
        {
            maxi = max(maxi,find(n-1,i,matrix,n,n,dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
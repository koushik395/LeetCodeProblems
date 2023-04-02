//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1));
    int wt[n];
    for(int i=0; i<n; i++)
    {
        wt[i] = i+1;
    }
    int cap = n;
    for(int i=0; i<=n; i++)
    {
        dp[0][i] = 0;
    }
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(wt[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                int cut = price[i-1] + dp[i][j-wt[i-1]];
                int notCut = dp[i-1][j];
                dp[i][j] = max(cut, notCut);
            }
        }
    }
    return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
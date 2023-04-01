//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	const int  M = 1e9+7; 
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1,vector<int>(sum+1));
	    for(int i=0;i< n+1;i++)
	    {
	        for(int j=0;j<sum+1;j++)
	        {
	            if(i==0 && j==0)
	                dp[i][j] = 1;
	            else if(i==0)
	                dp[i][j] = 0;
	            else if(arr[i-1]>j)
	                dp[i][j] = dp[i-1][j];
	            else
	            {
	                int take = dp[i-1][j-arr[i-1]];
	                int nottake = dp[i-1][j];
	                dp[i][j] = (take + nottake)%M;
	            }
	        }
	    }
        return dp[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
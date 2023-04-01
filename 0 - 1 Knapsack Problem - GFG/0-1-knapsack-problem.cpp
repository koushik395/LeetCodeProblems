//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1,vector<int>(W+1));
       for(int i =0;i<n+1;i++)
       {
           for(int j=0;j<W+1;j++)
           {
               if(i==0 || j == 0)
                 dp[i][j] = 0;
                else
                {
                    if(wt[i-1] > j)
                        dp[i][j] = dp[i-1][j];
                    else
                    {
                        int take = val[i-1] + dp[i-1][j-wt[i-1]];
                        int nottake = dp[i-1][j];
                        dp[i][j] = max(take,nottake);
                    }
                }
           }
       }
       return dp[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
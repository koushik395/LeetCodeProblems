//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  const int M=1e9 +7;
  public:
    int isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0 && j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = 0;
            // else if(j==0)
            //     dp[i][j] = 1;
            else
            {
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                {
                    int take = dp[i-1][j-arr[i-1]];
                    int nottake = dp[i-1][j];
                    dp[i][j] = (take+nottake)%M;   
                }
            }
            
        }
    }
    return dp[n][sum];
}
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
    	if((sum+d) & 1)
    		return 0;
    	int reqsum = (sum+d)>>1;
        return isSubsetSum(arr,reqsum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
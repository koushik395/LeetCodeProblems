//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int find(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>> &dp)
    {
    	if(i == n-1)
    	{
    		return triangle[n-1][j];
    	}
    
    	if(dp[i][j]!=-1) return dp[i][j];
    	int down = triangle[i][j] + find(i+1,j,n,triangle,dp);
    	int diag = triangle[i][j] + find(i+1,j+1,n,triangle,dp);
    
    	return dp[i][j] = min(down,diag);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        vector<vector<int>> dp(n,vector<int>(n,-1));
	   return find(0,0,n,triangle,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends
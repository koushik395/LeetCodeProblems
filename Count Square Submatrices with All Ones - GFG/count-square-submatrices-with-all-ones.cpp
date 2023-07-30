//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSquares(int n, int m, vector<vector<int>> &arr) {
        vector<vector<int>> dp(n,vector<int>(m,0));
        int tot = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(arr[i][j] == 1)
                {
                    if(i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                      dp[i][j] =
                          1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    }
                    tot += dp[i][j];
                }
            }
        }
        return tot;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends
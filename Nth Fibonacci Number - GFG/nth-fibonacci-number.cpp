//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        int mod = 1e9+7;
        int prev1 = 0,prev2 = 1,curr;
        for(int i = 2;i <= n;i++)
        {
            curr = (prev1 + prev2)%mod;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
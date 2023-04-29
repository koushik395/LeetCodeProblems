//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int m = 1e9 + 7;

    int power(int a, int b) {
        int res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (res * 1LL * a) % m;
            }
            a = (a * 1LL * a) % m;
            b >>= 1;
        }
        return res;
    }
    
    int nCr(int n, int r) {
        if (r > n) return 0;
        int res = 1;
        for (int i = 0; i < r; i++) {
            res = (res * 1LL * (n - i)) % m;
            res = (res * 1LL * power(i + 1, m - 2)) % m;
        }
        return res;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends
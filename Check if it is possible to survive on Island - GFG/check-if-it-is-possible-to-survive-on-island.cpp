//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int s, int n, int m){
        int sundays = s/7;
        int buydays = s - sundays;
        int totalFood = (s * m);
        int ans = 0;
        
        if(totalFood % n == 0)
        {
            ans = totalFood/n;
        }
        else
        {
            ans = totalFood/n + 1;
        }
        if(ans <= buydays) return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends
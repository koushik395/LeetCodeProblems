//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int arr[], int n)
    {
        int originalCount = 0, maxCount = 0, maxEndingHere = 0;
    
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                ++originalCount;
            }
            
            int val = (arr[i] == 1) ? -1 : 1;
            maxEndingHere = max(val, maxEndingHere + val);
            maxCount = max(maxCount, maxEndingHere);
        }
        
        return originalCount + maxCount;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
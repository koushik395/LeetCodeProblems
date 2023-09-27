//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int i = 0;
        int j = m - 1;

        int first = arr[i];
        int second = brr[j];

        int maxi = INT_MAX;

        while (i < n && j >= 0) {
            int sum = arr[i] + brr[j];
            int diff = abs(x - sum);
            if (diff < maxi) {
                maxi = diff;
                first = arr[i];
                second = brr[j];
            }
            if (sum < x) {
                i++;
            } else {
                j--;
            }
        }

        return {first,second};
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
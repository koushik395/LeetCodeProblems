//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
        long long pre = 1, suff = 1,maxi = INT_MIN;
        for(int i = 0; i< n;i++)
        {
            pre = pre * nums[i];
            suff = suff * nums[n-i-1];
            maxi = max({maxi,pre,suff});
            if(suff == 0) suff = 1;
            if(pre == 0) pre = 1;
        }
        return maxi;

	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
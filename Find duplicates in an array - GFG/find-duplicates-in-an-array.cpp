//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        set<int> st;
        vector<int> ans;
        int i = 0;
        while(i < n){
            if(i == arr[i])
            {
                i++;
                continue;
            }
            else if(arr[i] == arr[arr[i]])
            {
                st.insert(arr[i]);
                i++;
            }
            else
            {
                swap(arr[i],arr[arr[i]]);
            }
        }

        return st.empty()? vector<int>{-1} : vector<int>(st.begin(),st.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
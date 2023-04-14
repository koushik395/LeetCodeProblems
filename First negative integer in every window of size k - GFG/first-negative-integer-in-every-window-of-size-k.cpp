//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
                                                 
        vector<long long> res;
        deque<long long> q;
        
        for(int i=0;i<k;i++)
        {
            if(a[i] < 0)
                q.push_back(i);
        }
        if(q.size()>0)
            res.push_back(a[q.front()]);
        else
            res.push_back(0);
        
        for(int i = k;i<n;i++)
        {
            if(!q.empty() && (i-q.front()>=k))
                q.pop_front();
            
            if(a[i] < 0)
                q.push_back(i);
            
            if(q.size()>0)
                res.push_back(a[q.front()]);
            else
                res.push_back(0);
        }
        return res;
 }
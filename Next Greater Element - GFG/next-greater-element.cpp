//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    void solve(vector<long long> &arr, int n,vector<long long> &ans)
    {
        stack<long long> s;
        n--;
        s.push(-1);
        for(int i=n;i>=0;i--)
        {
            while(s.top()!= -1 && s.top() <=arr[i])
                s.pop();
            ans[i] = s.top();
            s.push(arr[i]);
        }
    }
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans(n);
        solve(arr,n,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
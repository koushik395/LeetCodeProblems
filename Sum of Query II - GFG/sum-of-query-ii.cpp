//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int N = 40000;
    vector<int> segment;

    Solution() {
        segment.resize(N);
    }
    
    void build(int index,int low,int high,int arr[])
    {
    	if(low == high)
    	{
    		segment[index] = arr[low];
    		return;
    	}
    
    	int mid = (low + high)/2;
    	build(2*index+1,low,mid,arr);
    	build(2*index+2,mid+1,high,arr);
    
    	segment[index] = segment[2*index+1] + segment[2*index+2];
    }
    
    int FindQuery(int low,int high,int left,int right,int index)
    {
    	if(low >= left && high <= right)
    	{
    		return segment[index];
    	}
    
    	if(high < left || low > right)
    	{
    		return 0;
    	}
    
    	int mid = (low+high)/2;
    	int maxi  = FindQuery(low,mid,left,right,2*index+1) +
    			   FindQuery(mid+1,high,left,right,2*index+2);
    
    	return maxi;
    }
    
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int> ans;
        build(0,0,n-1,arr);
        for(int i = 0;i < 2*q; i+=2)
        {
            int left = queries[i]-1;
            int right = queries[i+1]-1;
            
            ans.push_back(FindQuery(0,n-1,left,right,0));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
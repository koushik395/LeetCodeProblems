//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int nums[],int n,int m,int mid)
    {
    	int childrencount = 1,pageSum=0;
    	for(int i=0;i<n;i++)
    	{
    		if(pageSum+nums[i] <= mid)
    		{
    			pageSum += nums[i];
    		}
    		else{
    			childrencount++;
    			if((childrencount > m) || (nums[i] > mid))
    				return false;
    			pageSum = nums[i];
    		}
    	}
    	return true;
    }
    int findPages(int nums[], int n, int m) 
    {
        if(m > n) return -1;
        int sum = 0,ans = -1;
    	for(int i=0;i<n;i++)
    	{
    		sum += nums[i];
    	}
    	int low = 0,high = sum,mid;
    	while(low <= high)
    	{
    		mid = (low + high)/2;
    		if(isPossible(nums,n,m,mid))
    		{
    			ans = mid;
    			high = mid - 1;
    		}
    		else
    			low = mid + 1;
    	}
    	return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
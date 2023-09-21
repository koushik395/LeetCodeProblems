//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int find(int arr[],int index,vector<int>& dp)
    {
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int nottake = find(arr,index-1,dp);
        
        int take = arr[index] + find(arr,index-2,dp);
        
        return dp[index] = max(take,nottake);
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n,-1);
        return find(arr,n-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
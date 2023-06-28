//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int totalSum = accumulate(arr,arr+n,0);
	
    	int k = totalSum;
    	vector<bool> prev(k+1,false);
    
    	prev[0] = true;
    
    	if(arr[0]<=k)
    		prev[arr[0]] = true;
    
    	for(int ind = 1; ind<n; ind++){
    		vector<bool> cur(k+1,false);
    		cur[0] = true;
    		for(int target= 1; target<=k; target++){
    			bool notTaken = prev[target];
    
    			bool taken = false;
    				if(arr[ind]<=target)
    					taken = prev[target-arr[ind]];
    
    			cur[target]= notTaken||taken;
    		}
    		prev = cur;
    	}
    
    	int mini = 1e9;
    	for(int s1 = 0;s1 <= totalSum/2;s1++)
    	{
    		if(prev[s1]==true)
    		{
    			mini  = min(mini,abs(s1-(totalSum-s1)));
    		}
    	}
    	return mini;
    } 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
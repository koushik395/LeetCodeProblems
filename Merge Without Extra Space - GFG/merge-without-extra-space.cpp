//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        void checkSwap(long long arr1[], long long arr2[],int idx1,int idx2)
        {
            if(arr1[idx1] > arr2[idx2])
                swap(arr1[idx1],arr2[idx2]);
        }
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int size = n+m;
            int gap = (size)/2 + size%2;
            while(gap > 0)
            {
                int start = 0;
                int right = start + gap;
                while(right < size)
                {
                    if(start < n && right >=n)
                    {
                        checkSwap(arr1,arr2,start,right-n);
                    }
                    else if(start >= n)
                    {
                        checkSwap(arr2,arr2,start-n,right-n);   
                    }
                    else
                    {
                        checkSwap(arr1,arr1,start,right);
                    }
                    start++;
                    right++;
                }
                if(gap == 1)break;
                gap = gap/2 + gap%2;
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends
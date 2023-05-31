//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        int i,j;
        for(i = 0,j = k-1; j < arr.size();i += k,j += k)
        {
            int x = i,y = j;
            while(x < y)
            {
                swap(arr[x],arr[y]);
                x++;
                y--;
            }
        }
        if(i < arr.size())
        {
            j = arr.size()-1;
            while(i < j)
            {
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
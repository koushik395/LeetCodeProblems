//{ Driver Code Starts


#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    long long noOfDigits(int N){
        if(N <= 1) return N;
        
        double phi = (1 + sqrt(5)) / 2;
        double fibN = (pow(phi,N) - pow(-phi,-N))/sqrt(5);
        return floor(log10(fibN)) + 1;
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.noOfDigits(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
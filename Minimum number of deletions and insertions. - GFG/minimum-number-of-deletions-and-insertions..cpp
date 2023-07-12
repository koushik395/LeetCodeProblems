//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int lcs(string text1, string text2,int m,int n)
    {
        vector<int> prev(m+1,0),curr(n+1,0);
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    curr[j] =0;
                else if(text1[i-1] == text2[j-1])
                    curr[j] = 1+ prev[j-1];
                else
                {
                    int a = prev[j];
                    int b = curr[j-1];
                    curr[j] = max(a,b);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.length();
	    int m = str2.length();
	    
	    return n + m - 2*(lcs(str1,str2,n,m));
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int longestCommonSubstr(string text1, string text2, int m, int n)
    {
        int maxNum = 0;
    	vector<int> prev(n+1,0) , curr(n+1,0);
    	for(int i=0;i<m+1;i++)
    	{
    		for(int j=0;j<n+1;j++)
    		{
    			if(i==0 || j==0)
    				curr[j] =0;
    			else if(text1[i-1] == text2[j-1])
    			{
    				curr[j] = 1+ prev[j-1];
    				maxNum = max(maxNum,curr[j]);
    			}
    			else
    			{
    				curr[j] = 0;
    			}
    		}
    		prev = curr;
    	}
    	return maxNum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
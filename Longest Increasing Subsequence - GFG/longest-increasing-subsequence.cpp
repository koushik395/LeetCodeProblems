//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    // int recursive(int n,int a[],int ind,int prev_ind,vector<vector<int>> &dp)
    // {
    //     if(ind == n)
    //     {
    //         return 0;
    //     }
        
    //     if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        
    //     int nottake = recursive(n,a,ind+1,prev_ind,dp);
        
    //     int take = 0;
    //     if(prev_ind == -1 || a[ind] > a[prev_ind])
    //     {
    //         take = 1 + recursive(n,a,ind+1,ind,dp);
    //     }
        
    //     return dp[ind][prev_ind+1] = max(take,nottake);
    // }
    int longestSubsequence(int n, int nums[])
    {
        vector<int> sub;
        for(int i = 0;i < n;i++)
        {
            int x = nums[i];
            if(sub.empty() || sub[sub.size()-1] < x)
            {
                sub.push_back(x);
            }
            else
            {
                auto it = lower_bound(sub.begin(),sub.end(),x);
                *it = x;
            }
        }
        return sub.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
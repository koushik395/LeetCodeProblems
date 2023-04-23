//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> ans(start.size());
        int count = 0;
        for(int i=0;i<start.size();i++)
        {
            ans.push_back({end[i],start[i]});
        }
        sort(ans.begin(),ans.end());
        
        int prev = 0;
        for(auto& pr:ans)
        {
            if(prev<pr.second)
            {
                count++;
                prev = pr.first;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
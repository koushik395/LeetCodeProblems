//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> time;
        for(int i = 0;i < n;i++)
        {
            time.push_back({end[i],start[i]});
        }
        sort(time.begin(),time.end());
        
        int count = 0;
        int endTime = -1;
        for(int i = 0;i < n;i++)
        {
            int et = time[i].first;
            int st = time[i].second;
            
            if(st > endTime)
            {
                count++;
                endTime = et;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
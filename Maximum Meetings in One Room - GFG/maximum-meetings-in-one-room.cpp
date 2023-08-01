//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxNum(vector<int> &start, vector<int> &end, int n)
    {
        vector<pair<int,pair<int,int>>> time;
        vector<int> ans;
        for(int i = 0;i < n;i++)
        {
            time.push_back({end[i],{start[i],i+1}});
        }
        sort(time.begin(),time.end());

        int endTime = -1;
        for(int i = 0;i < n;i++)
        {
            int et = time[i].first;
            int st = time[i].second.first;
            int mn = time[i].second.second;
            
            if(st > endTime)
            {
                ans.push_back(mn);
                endTime = et;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        return maxNum(S,F,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
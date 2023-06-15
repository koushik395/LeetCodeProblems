//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    typedef pair<long long,long long> P;
    typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<pair<int,int>> adj[n];
        for(auto& it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<P,vector<P>,greater<P>> q;
        q.push({0,0});  //dist, startNode
        vector<ll> dist(n,1e18);
        vector<ll> ways(n,0);
        
        dist[0] = 0;
        ways[0] = 1;
        while(!q.empty())
        {
            ll front = q.top().second;
            ll distance = q.top().first;
            q.pop();
            for(auto it:adj[front])
            {
                ll neigh = it.first;
                ll weigh = it.second;
                
                if(distance + weigh < dist[neigh])
                {
                    dist[neigh] = distance + weigh;
                    q.push({distance + weigh,neigh});
                    ways[neigh] = ways[front];
                }
                else if(distance + weigh <= dist[neigh])
                {
                    ways[neigh] = (ways[neigh] + ways[front])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
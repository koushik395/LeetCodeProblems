//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<int> &ans,int start,vector<int> adj[],vector<bool> &visited)
    {
        if(visited[start]==true)
            return;
        ans.push_back(start);
        visited[start] = true;
        for(auto& neighbour:adj[start])
        {
            dfs(ans,neighbour,adj,visited);
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<bool> visited(v,false);
        vector<int> ans;
        dfs(ans,0,adj,visited);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
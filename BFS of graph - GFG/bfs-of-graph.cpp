//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(vector<int> adj[],vector<int> &ans,unordered_map<int,bool> visited,int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto& neighbour:adj[front])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int,bool> visited;
        bfs(adj,ans,visited,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
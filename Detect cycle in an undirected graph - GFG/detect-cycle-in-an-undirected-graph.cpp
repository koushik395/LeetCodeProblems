//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool is_cyclic_util(int v, vector<bool>& visited, int parent,vector<int> adj[]) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (is_cyclic_util(neighbor, visited, v,adj)) {
                    return true;
                }
            }
            else if (parent != neighbor) {
                return true;
            }
        }

        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                if (is_cyclic_util(v, visited, -1,adj)) {
                    return true;
                }
            }
        }

        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
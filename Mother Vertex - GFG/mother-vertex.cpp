//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(int node,vector<int>& vis,vector<int> adj[])
    {
        vis[node] = 1;
        for(auto& it: adj[node])
        {
            if(vis[it] == 0)
            {
                dfs(it,vis,adj);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    int lastVisitedVertex = 0;
	    
	    for(int i = 0;i < V;i++)
	    {
	        if(!vis[i])
	        {
    	        dfs(i,vis,adj);
    	        lastVisitedVertex = i;
	        }
	    }
	    
	    fill(vis.begin(), vis.end(), false);
	    dfs(lastVisitedVertex,vis,adj);
	    
	    for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                return -1; // No mother vertex found
            }
        }
    
        return lastVisitedVertex;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
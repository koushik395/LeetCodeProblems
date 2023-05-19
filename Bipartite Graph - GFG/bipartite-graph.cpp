//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool valid(vector<int> graph[], vector<int>& colors, int node, int color) {
        if (colors[node]) {
            return colors[node] == color;
        }
        colors[node] = color;
        for (int neigh : graph[node]) {
            if (!valid(graph, colors, neigh, -color)) {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
        vector<int> colors(V, 0);
        for (int i = 0; i < V; i++) {
            if (!colors[i] && !valid(adj, colors, i, 1)) {
                return false;
            }
        }
        return true;
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
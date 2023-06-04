//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    int timer = 0;
    void dfs(int node,int parent,vector<int> &vis,vector<int> adj[],vector<int> &tin,vector<int> &low,vector<int> &mark)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        int child = 0;
        for(auto& neigh:adj[node])
        {
            if(neigh == parent)continue;
            if(vis[neigh] == 0)
            {
                dfs(neigh,node,vis,adj,tin,low,mark);
                //while backtracking take out the min lowest value for the node
                low[node] = min(low[node],low[neigh]);
                //can this be Point?
                if(low[neigh] >= tin[node] && parent!=-1) //neigh cannot reach before point
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node],tin[neigh]);
            }
        }
        if(child > 1 && parent == -1) mark[node]=1;//starting node
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> visited(n),tin(n,0),low(n,0),mark(n,0);
        for(int i = 0;i < n;i++)
        {
            if(!visited[i])
            {
                dfs(0,-1,visited,adj,tin,low,mark);
            }
        }
        vector<int> ans;
        for(int i = 0;i < n;i++)
        {
            if(mark[i])
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
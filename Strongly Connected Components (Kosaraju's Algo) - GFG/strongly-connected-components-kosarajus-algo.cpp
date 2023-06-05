//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int node,vector<int>& visited,vector<vector<int>>& adj,stack<int>&st)
    {
        visited[node] = 1;
        for(auto& neigh:adj[node])
        {
            if(!visited[neigh])
            {
                dfs(neigh,visited,adj,st);   
            }
        }
        
        st.push(node);
    }
    
    void dfs1(int node,vector<int>& visited,vector<int> adj[])
    {
        visited[node] = 1;
        for(auto& neigh:adj[node])
        {
            if(!visited[neigh])
            {
                dfs1(neigh,visited,adj);   
            }
        }
        
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //find Timelines
        vector<int> visited(V,0);
        stack<int> st;
        //O(V+E)
        for(int i = 0;i < V;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,adj,st);
            }
        }
        
        //reverse Graph
        //O(V+E)
        vector<int> adjT[V];
        for(int i = 0;i < V;i++)
        {
            visited[i] = 0;
            for(auto& it:adj[i])
            {
                //reverse edge
                adjT[it].push_back(i);
            }
        }
        
        //find SCC
        //O(V+E)
        int scc = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(!visited[node])
            {
                scc++;
                dfs1(node,visited,adjT);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void calculate(vector<int> &indegree,vector<int> adj[],int child)
	{
	    for(auto& neighbour:adj[child])
	    {
	        indegree[neighbour]++;
	    }
	}
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> visited(v,0); 
	    queue<int> q;
	    vector<int> indegree(v,0);
	    
	    for(int i=0;i<v;i++)
	    {
	        calculate(indegree,adj,i);
	    }
	    for(int i=0;i<v;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    while(q.size()!=0)
	    {
	        int front = q.front();
	        q.pop();
	        visited[front] =true;
	        for(auto& neighbour:adj[front])
	        {
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
	        }
	    }
	    for(auto& node: visited)
	    {
	        if(!node) return true;
	    }
	    return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
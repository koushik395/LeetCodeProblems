//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool checkCycleDFS(int node,int visited[], int dfsvisited[],vector<int> adj[],int check[])
    {
      visited[node] = true;
      dfsvisited[node] = true;
      check[node] = 0;
      for(auto& neighbour:adj[node])
      {
        if(!visited[neighbour])
        {
          bool  cycledetected = checkCycleDFS(neighbour,visited,dfsvisited,adj,check);
          if(cycledetected){
              check[node] = 0;
              return true;  
          } 
        }
        else if(dfsvisited[neighbour])
        {
            check[node] = 0;
            return true;
        }
      }
      check[node] = 1;
      dfsvisited[node] = false;
      return false; 
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int visited[V] = {0};
        int dfsvisited[V] = {0};
        int check[V] = {0};
        vector<int> safeNode;
        for(int i = 0;i<V;i++)
        {
          if(!visited[i])
          {
            checkCycleDFS(i,visited,dfsvisited,adj,check);
          }
        }
        for(int i = 0;i < V;i++)
        {
            if(check[i] == 1) safeNode.push_back(i);
        }
        return safeNode;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
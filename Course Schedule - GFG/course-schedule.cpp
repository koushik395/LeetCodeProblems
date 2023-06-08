//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
        void calculate(vector<int> &indegree,vector<vector<int>> &adj,int child)
    	{
    	    for(auto& neighbour:adj[child])
    	    {
    	        indegree[neighbour]++;
    	    }
    	}
    	vector<int> topoSort(int v, vector<vector<int>> &adj) 
    	{
    	    vector<int> ans;
    	    queue<int> q;
    	    vector<int> indegree(v,0);
    	    int count =0;
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
    	        ans.push_back(front);
                count++;
    	        q.pop();
    	        for(auto& neighbour:adj[front])
    	        {
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0) q.push(neighbour);
    	        }
    	    }
            if(count == v)
            {
                return ans;
            }
            return {};
    	}
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> adj(n);
        for(auto& v:prerequisites)
        {
            adj[v[1]].push_back(v[0]);
        }
        return topoSort(n,adj);
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
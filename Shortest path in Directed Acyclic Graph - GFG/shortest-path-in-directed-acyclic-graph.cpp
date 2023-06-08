//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  vector <int> dijkstra(int v, vector<pair<int,int>> adj[], int start)
    {
        vector<int> distance(v,INT_MAX);
    	set<pair<int,int>> q;
    
    	distance[start] = 0;
    	q.insert({0,start});
    
    	while(!q.empty())
    	{
    	    auto it = *q.begin();
    		int node = it.second;
    		int dist = it.first;
    		q.erase(it);
    		for(auto& neightbour: adj[node])
    		{
    			int child = neightbour.second;
    			int wt = neightbour.first;
    			if(wt+dist < distance[child])
    			{
    			    if(distance[child]!=INT_MAX)
    			        q.erase({distance[child],child});
    				distance[child] = wt+dist;
    				q.insert({wt+dist,child});
    			}
    		}
    	}
    	return distance;
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(auto&it:edges)
        {
            adj[it[0]].push_back({it[2],it[1]});
        }
        vector<int> ans=  dijkstra(N,adj,0);
        for(int i = 0;i < N;i++)
        {
            if(ans[i] == INT_MAX)
            {
                ans[i]  = -1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
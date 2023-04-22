//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int start)
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
    			int child = neightbour[0];
    			int wt = neightbour[1];
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
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
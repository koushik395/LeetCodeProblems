//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V,false);
        vector<int> parent(V,-1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0,0});
        key[0] = 0;

        while(pq.size()) {
            int w = pq.top().first;
            int node = pq.top().second;
            mst[node] = 1;
            pq.pop();

            for(auto neg: adj[node]) {
                int toGo = neg[0];
                int toGoWeg = neg[1];

                if(mst[toGo] == 0 && toGoWeg < key[toGo]) {

                    key[toGo] = toGoWeg;
                    parent[toGo] = node;
                    pq.push({toGoWeg, toGo});
                }
            }
        }
        int sum = 0;
        for(int i = 1;i < V;i++)
        {
           sum +=  key[i];
        }
        return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
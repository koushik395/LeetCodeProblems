class Solution {
    private:
    int timer = 1;
    void dfs(int node,int parent,vector<int> &vis,vector<int> adj[],vector<int> &tin,vector<int> &low,vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        for(auto& neigh:adj[node])
        {
            if(neigh == parent)continue;
            if(vis[neigh] == 0)
            {
                dfs(neigh,node,vis,adj,tin,low,bridges);
                low[node] = min(low[node],low[neigh]);
                //can this be bridge?
                if(low[neigh] > tin[node]) //cannot reach
                {
                    bridges.push_back({node,neigh});
                }
            }
            else
            {
                low[node] = min(low[node],low[neigh]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto& it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> visited(n),tin(n,0),low(n,0);
        
        vector<vector<int>> bridges;
        dfs(0,-1,visited,adj,tin,low,bridges);
        return bridges;
    }
};
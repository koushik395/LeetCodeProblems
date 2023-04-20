class Solution {
public:
    void dfs(int n,int source,int destination,vector<vector<int>> &adj,vector<bool> &visited)
    {
        visited[source] =true;
        if(source == destination)
            return;
        for(auto& neighbour:adj[source]){
            if(!visited[neighbour])
                dfs(n,neighbour,destination,adj,visited);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int sv,dv;
        vector<vector<int>> adjList(n);
        vector<bool> visited(n,false);
        for(auto& v:edges)
        {
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
        }
        dfs(n,source,destination,adjList,visited);
        if(visited[destination]==1)
            return true;
        return false;
    }
};
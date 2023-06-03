class Solution {
public:
    int dfs(vector<int> adj[],vector<int>& informTime,int node,vector<int> &visited)
    {
        visited[node] = true;
        int maxi = 0;
        int sum;
        for(auto& neigh: adj[node])
        {
            if(!visited[neigh])
            {
                sum = informTime[node] + dfs(adj,informTime,neigh,visited);
                maxi  = max(maxi,sum);
            }
        }
        return maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return 0;
        vector<int> adj[n];
        for(int i = 0;i < n ;i++)
        {
            int parent = manager[i];
            int child = i;
            if(parent!=-1)
            {
                adj[parent].push_back(child);
            }
        }
        
        vector<int> visited(n);
        return dfs(adj,informTime,headID,visited);
    }
};
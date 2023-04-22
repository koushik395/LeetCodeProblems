class Solution {
public:
    void dfs(vector<int> adj[], vector<bool>& hasApple, int start, vector<bool>& visited, int& time)
{
    visited[start] = true;
    for (auto& neighbour : adj[start])
    {
        if (!visited[neighbour])
        {
            dfs(adj, hasApple, neighbour, visited, time);
            if (hasApple[neighbour])
            {
                time += 2;
                hasApple[start] = true;
            }
        }
    }
}

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
    {
        vector<int> adj[n];
        vector<bool> visited(n, false);
        int time = 0;
        for (auto& v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs(adj, hasApple, 0, visited, time);
        return time;
    }

};
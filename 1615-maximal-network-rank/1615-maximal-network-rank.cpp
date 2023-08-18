class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        unordered_set<int> adj[n];
        for(int i = 0;i < roads.size();i++)
        {
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
            
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }
        
        int res = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = i+1;j < n;j++)
            {
                int connected = (adj[i].find(j) == adj[i].end()) ? 0:1;
                res = max(res,indegree[i]+indegree[j]-connected);
            }
        }
        return res;
    }
};
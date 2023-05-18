class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n],ans;
        vector<int> indegree(n,0);
        for(auto& node:edges)
        {
            adj[node[0]].push_back(node[1]);
            indegree[node[1]]++;
        }
        for(int i = 0;i<n;i++)
        {
            if(indegree[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
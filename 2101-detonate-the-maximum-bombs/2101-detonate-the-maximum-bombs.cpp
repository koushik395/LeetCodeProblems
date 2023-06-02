class Solution {
public:
    void dfs(vector<int> adj[],int start,bitset<101> &visited)
    {
        visited.set(start);
        
        for(auto& neighbour: adj[start])
        {
            if(!visited[neighbour])
            {
                dfs(adj,neighbour,visited);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        
        for(int i = 0;i < n;i++)
        {
            long long x = bombs[i][0];
            long long y = bombs[i][1];
            long long r = bombs[i][2];
            
            for(int j = 0;j < n;j++)
            {
                if(i!=j)//self bomb
                {
                    long long x1 = abs(x - bombs[j][0]);
                    long long y1 = abs(y - bombs[j][1]);
                    if(x1*x1 + y1*y1 <= r*r)
                    {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int maxi = -1,count;
        bitset<101> visited;
        for(int i = 0;i < n;i++)
        {
            visited.reset();
            dfs(adj,i,visited);
            count = visited.count();
            maxi = max(maxi,count);
        }
        return maxi;
    }
};
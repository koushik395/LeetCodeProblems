class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<double,int>> adj[n];
        for(int i = 0;i < edges.size();i++)
        {
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        
        vector<double> distance(n,-1e9);
        priority_queue<pair<double,int>> q;
        q.push({1.0,start});// prob,node
        distance[start] =1.0;
        
        while(!q.empty())
        {
            int node = q.top().second;
            double dist = q.top().first;
            q.pop();
            
            if(node == end)
            {
                return dist;
            }
            
            for(auto neigh: adj[node])
            {
                int child = neigh.second;
                double wt = neigh.first;
                
                if(dist * wt > distance[child])
                {
                    q.push({dist*wt,child});
                    distance[child] = dist*wt;
                }
            } 
        }
        return 0;
    }
};
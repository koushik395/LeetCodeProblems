class Solution {
public:
    vector <int> dijkstra(int v, vector<pair<int,int>> adj[], int start)
    {
        vector<int> distance(v+1,INT_MAX);
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
                int child = neightbour.second;
                int wt = neightbour.first;
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
    int networkDelayTime(vector<vector<int>>& times, int v, int start) {
        vector<pair<int,int>> adj[v+1];
        int sv,ev,cost;
        for(auto& edges:times)
        {
            sv = edges[0];
            ev = edges[1];
            cost = edges[2];
            adj[sv].push_back({cost,ev});
        }
        vector<int> distance = dijkstra(v,adj,start);
        
        int maxDist = 0;
        for (int i = 1; i <= v; i++) {
            if (distance[i] == INT_MAX)
                return -1;
            maxDist = max(maxDist, distance[i]);
        }
        return maxDist;
    }
};
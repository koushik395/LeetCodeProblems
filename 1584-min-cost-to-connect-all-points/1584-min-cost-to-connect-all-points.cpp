class DSU {
    vector<int> parent, size; 
    int components;
public: 
    DSU(int n) {
        components = n;
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findParent(parent[node]); 
    }

    bool unionBySize(int u, int v) {
        int ulp_u = findParent(u); 
        int ulp_v = findParent(v); 
        if(ulp_u == ulp_v) return false; 
        components--;
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
        return true;
    }
    
    bool united() {
        return components == 1;
    }
}; 

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<array<int,3>> ksk;
        int n = points.size();
        
        for(int i = 0;i < n-1;i++)
        {
            for(int j = i+1;j < n;j++)
            {
                int dist = abs(points[i][0]-points[j][0])
                           + abs(points[i][1]-points[j][1]);
                ksk.push_back({dist, i, j}); // Add the edge.
            }
        }
        
        sort(ksk.begin(),ksk.end());
        
        int cost = 0;
        DSU ds(n);
        
        for(auto& it:ksk)
        {
            if(ds.united()) break;
            int p1 = it[1];
            int p2 = it[2];
            int cst = it[0];
            
            if(ds.unionBySize(p1,p2))
            {
                cost += cst;
            }
        }
        return cost;
    }
};
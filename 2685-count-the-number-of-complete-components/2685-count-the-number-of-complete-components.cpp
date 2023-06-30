class DSU { 
public: 
    vector<int> parent, size,edges;
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        edges.resize(n,0);
        for(int i = 0;i<n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findParent(parent[node]); 
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findParent(u); 
        int ulp_v = findParent(v);
        edges[ulp_u] += 1;
            
        if(ulp_u == ulp_v) return; 
        
        parent[ulp_v] = ulp_u; 
        size[ulp_u] += size[ulp_v];
        edges[ulp_u] += edges[ulp_v];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        for(auto& it:edges)
        {
            int x = it[0];
            int y = it[1];
            ds.unionBySize(x,y);
        }
        
        int cnt = 0;
        for(int i = 0;i < n;i++)
        {
            int nodes = ds.size[i];
            int edges = ds.edges[i];
            if(i == ds.parent[i] && nodes*(nodes-1)/2 == edges) cnt++;
        }
        return cnt;
    }
};
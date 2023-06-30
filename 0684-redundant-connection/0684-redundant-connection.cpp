class DSU {
    vector<int> parent, size; 
public: 
    DSU(int n) { 
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

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u); 
        int ulp_v = findParent(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n);
        
        int redux = -1,redy = -1;
        for(int i = 0; i < n;i++)
        {
            if(ds.findParent(edges[i][0]) != ds.findParent(edges[i][1]))
            {
                ds.unionBySize(edges[i][0],edges[i][1]);   
            }
            else
            {
                redux = edges[i][0];
                redy = edges[i][1];
            }
        }
        
        return {redux,redy};
    }
};
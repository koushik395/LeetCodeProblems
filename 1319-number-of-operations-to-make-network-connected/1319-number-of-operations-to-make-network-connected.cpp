class DSU {
public: 
    vector<int> parent, size; 
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
    int makeConnected(int n, vector<vector<int>>& edge) {
        DSU dsu(n);
        
        int cntExtra = 0;
        for(auto& it: edge)
        {
            int u = it[0];
            int v = it[1];
            if(dsu.findParent(u) == dsu.findParent(v))
            {
                cntExtra++;
                
            }
            else
            {
                dsu.unionBySize(u,v);
            }
        }
        int cntC = 0;
        for(int i = 0;i < n;i++)
        {
            if(dsu.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if(cntExtra >= ans)
        {
            return ans;
        }
        return -1;
    }
};
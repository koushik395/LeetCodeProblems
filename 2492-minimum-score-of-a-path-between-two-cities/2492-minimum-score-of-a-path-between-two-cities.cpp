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
    
    int minScore(int n, vector<vector<int>>& roads) {
        DSU ds(n);
        for(auto &x : roads) 
        {
            ds.unionBySize(x[0],x[1]);
        }
        
        int mini=INT_MAX;
        for(int i = 1;i <= n;i++) ds.findParent(i);
        
        int one = ds.parent[1];
        for(int i=0;i<roads.size();i++)
        {
           if(ds.parent[roads[i][0]]==one)
               mini=min(roads[i][2],mini);    
        }
        return mini;
    }
};
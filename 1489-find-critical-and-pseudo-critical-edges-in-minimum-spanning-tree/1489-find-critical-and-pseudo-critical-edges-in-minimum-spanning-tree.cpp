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
    static bool cmp(vector<int>& a,vector<int> &b)
    {
      return a[2] < b[2];
    }
    
    int MST(int n,vector<vector<int>>& edges,int ignore,int include)
    {
        DSU ds(n);
        
        int total = 0;
        if(include != -1) //include this edge to find psuedo-critical
        {
            ds.unionBySize(edges[include][0],edges[include][1]);
            total += edges[include][2];
        }
        
        for(int i = 0;i < edges.size();i++)
        {
            if(i == ignore) continue; //ignore this edge to find critical edge
            int from = edges[i][0],to = edges[i][1],weight = edges[i][2];
            if(ds.findParent(from) != ds.findParent(to))
            {
                ds.unionBySize(from,to);
                total += weight;   
            }
        }
        
        for(int i = 0;i < n;i++)
        {
            if(ds.findParent(i) != ds.findParent(0)) return 1e9;
        }
        return total;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical,pseudo;
        
        for(int i = 0; i < edges.size(); ++i){
            edges[i].push_back(i);
        }
        
        sort(edges.begin(),edges.end(),cmp);
        
        int original_MST = MST(n, edges, -1, -1);

        for(int i = 0;i < edges.size();i++)
        {
            //ignore edge and if greater than original weight
            if(MST(n,edges,i,-1) > original_MST) critical.push_back(edges[i][3]);
            //include edge and if is equal to original weight
            else if(MST(n,edges,-1,i) == original_MST) pseudo.push_back(edges[i][3]);
        }
        
        return {critical,pseudo};
    }
};
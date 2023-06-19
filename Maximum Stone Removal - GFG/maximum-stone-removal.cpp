//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxrow = 0;
        int maxcol = 0;
        
        for(auto& it: stones)
        {
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        
        DSU ds(maxrow+maxcol+1);
        
        unordered_map<int,int> stoneNodes;
        for(auto& it:stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxrow + 1;
            ds.unionBySize(nodeRow,nodeCol);
        }
        
        int cnt = 0;
        for(int i=0;i<(maxrow+maxcol+1);i++){
            if(ds.parent[i]==i && ds.size[i]>1) cnt+=1;   
        }
        return n - cnt; // number of stones - number of connected components
        // for each component of size n we can remove n-1 stones
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends
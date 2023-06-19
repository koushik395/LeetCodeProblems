//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    vector<vector<int>> direc = {{0,-1},{-1,0},{1,0},{0,1}};
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DSU dsu(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt = 0;
        vector<int> ans;
        
        auto isvalid = [&](const int &newx,const int &newy)
        {
            return (newx >=0 && newx < n && newy >=0 && newy < m);
        };
        
        for(auto& it:operators)
        {
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            
            for(auto& it: direc)
            {
                int newx = row + it[0];
                int newy = col + it[1];
                if(isvalid(newx,newy) && vis[newx][newy] == 1)
                {
                    int nodeno = row * m + col;
                    int adjno = newx * m + newy;
                    if(dsu.findParent(nodeno) != dsu.findParent(adjno))
                    {
                        cnt--;
                        dsu.unionBySize(nodeno,adjno);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
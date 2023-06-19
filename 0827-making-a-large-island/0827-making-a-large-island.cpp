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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(),onesCount = 0;
        DSU ds(n*n);
        
        auto isvalid = [&](const int &newx,const int &newy)
        {
            return (newx >=0 && newx < n && newy >=0 && newy < n);
        };
        
        for(int row = 0;row < n;row++)
        {
            for(int col = 0;col < n;col++)
            {
                if(grid[row][col] == 0)continue;
                onesCount++;
                for(auto& it: direc)
                {
                    int newx = row + it[0];
                    int newy = col + it[1];
                    if(isvalid(newx,newy) && grid[newx][newy] == 1)
                    {
                        int nodeno = row * n + col;
                        int adjno = newx * n + newy;
                        if(ds.findParent(nodeno) != ds.findParent(adjno))
                        {
                            ds.unionBySize(nodeno,adjno);
                        }
                    }
                }
            }
        }
        
        int mx = 0;
        for(int row = 0;row < n;row++)
        {
            for(int col = 0;col < n;col++)
            {
                if(grid[row][col] == 1)continue;
                unordered_set<int> st;
                for(auto& it: direc)
                {
                    int newx = row + it[0];
                    int newy = col + it[1];
                    if(isvalid(newx,newy) && grid[newx][newy] == 1)
                    {
                        int adjno = newx * n + newy;
                        st.insert(ds.findParent(adjno));
                    }
                }
                int sizeTotal = 0;
                for(auto& it:st)
                {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx,sizeTotal+1);
            }
        }
        // if matrix has all 1's
        if(onesCount == n * n)
        {
            return ds.size[0];
        }
        return mx;
    }
};
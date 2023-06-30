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
    int latestDayToCross(int n, int m, vector<vector<int>>& C) {
        int row = C.size();
        int col = C[0].size();
        DSU dsu(m * n + 1);
        vector<vector<int>> grid(n, vector<int>(m, 1));
        vector<vector<int>> neibs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < row; i++) {
            C[i][0]--;
            C[i][1]--;
        }

        auto index = [&](int &x, int &y) {
            return x * m + y + 1;
        };

        for (int i = row - 1; i >= 0; i--) {
            int x = C[i][0];
            int y = C[i][1];

            grid[x][y] = 0;
            for (auto& neib : neibs) {
                int dx = neib[0];
                int dy = neib[1];
                int newX = x + dx;
                int newY = y + dy;
                int ind = index(newX, newY);
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 0) {
                    dsu.unionBySize(ind, index(x, y));
                }
            }
            if (x == 0) {
                dsu.unionBySize(0, index(x, y));
            }
            if (x == n - 1) {
                dsu.unionBySize(m * n + 1, index(x, y));
            }

            if (dsu.findParent(0) == dsu.findParent(m * n + 1)) {
                return i;
            }
        }

        return -1;
    }
};

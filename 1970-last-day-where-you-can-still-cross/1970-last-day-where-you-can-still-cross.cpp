class DSU {
private:
    vector<int> p;

public:
    DSU(int N) {
        p.resize(N);
        for (int i = 0; i < N; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void unionSet(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        p[xr] = yr;
    }
};

class Solution {
public:
    int latestDayToCross(int n, int m, vector<vector<int>>& C) {
        int row = C.size();
        int col = C[0].size();
        DSU dsu(m * n + 2);
        vector<vector<int>> grid(n, vector<int>(m, 1));
        vector<vector<int>> neibs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < row; i++) {
            C[i][0]--;
            C[i][1]--;
        }

        auto index = [m](int x, int y) {
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
                    dsu.unionSet(ind, index(x, y));
                }
            }
            if (x == 0) {
                dsu.unionSet(0, index(x, y));
            }
            if (x == n - 1) {
                dsu.unionSet(m * n + 1, index(x, y));
            }

            if (dsu.find(0) == dsu.find(m * n + 1)) {
                return i;
            }
        }

        return -1; // or any other suitable value
    }
};

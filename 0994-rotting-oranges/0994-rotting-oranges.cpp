class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();


        queue < pair < pair < int, int > , int >> q;
        int cntFresh = 0;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {

            if (grid[i][j] == 2) {
              q.push({{i, j}, 0}); 

            }

            if (grid[i][j] == 1) cntFresh++;
          }
        }

        auto isSafe = [&](int& nrow,int &ncol)
        {
              return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1);
        };

        int tm = 0;

        int cnt = 0; //to track no. of fresh oranges visited
        int t = -1;
        while (!q.empty()) {
          int r = q.front().first.first;
          int c = q.front().first.second;
          t = q.front().second;
          // tm = max(tm, t);
          q.pop();

          for(auto& dir: directions) {

            int nrow = r + dir[0];
            int ncol = c + dir[1];

            if (isSafe(nrow,ncol)) {

               q.push({{nrow, ncol}, t + 1}); 

              grid[nrow][ncol] = 2;
              cnt++;
            }
          }
        }

        // if all oranges are not rotten
        if (cnt != cntFresh) return -1;

        return t == -1?0:t;
    }
};
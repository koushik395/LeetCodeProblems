class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n,vector<int>(m,0));
    
        queue < pair < pair < int, int > , int >> q;

        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
    
            if (grid[i][j] == 0) {
              q.push({{i, j}, 0}); 
              
            }
          }
        }
        
        auto isSafe = [&](int& nrow,int &ncol)
        {
              return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1);
        };
    
    
        while (!q.empty()) {
          int r = q.front().first.first;
          int c = q.front().first.second;
          int t = q.front().second;
          
          res[r][c] = t;
          q.pop();
          
          for(auto& dir: directions) {
    
            int nrow = r + dir[0];
            int ncol = c + dir[1];
    
            if (isSafe(nrow,ncol)) {
    
               q.push({{nrow, ncol}, t + 1}); 
    
              grid[nrow][ncol] = 0;
            }
          }
        }
    
    
        return res;
    }
};
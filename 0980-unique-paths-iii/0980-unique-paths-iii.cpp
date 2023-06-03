class Solution {
public:
    int dfs(vector<vector<int>>& g, int i, int j, int s, int empcells) {
          if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1) return 0;
          if (g[i][j] == 2) return s == empcells-1 ? 1 : 0;
          g[i][j] = -1;
          int paths = dfs(g, i + 1, j, s + 1, empcells) + dfs(g, i - 1, j, s + 1, empcells) +
            dfs(g, i, j + 1, s + 1, empcells) + dfs(g, i, j - 1, s + 1, empcells);
          g[i][j] = 0;
          return paths;
    }
    int uniquePathsIII(vector<vector<int>>& g) {
      int x = 0, y = 0, empcells = 0;
      for (auto i = 0; i < g.size(); ++i)
        for (auto j = 0; j < g[0].size(); ++j) {
          if (g[i][j] == 1) x = i, y = j;
          if (g[i][j] != -1) ++empcells;
        }
      return dfs(g, x, y, 0, empcells);
    }
};
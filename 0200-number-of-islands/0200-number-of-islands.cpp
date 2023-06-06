class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(int &rows,int &cols,int x,int y,vector<vector<char>>& grid)
    {
        auto isSafe = [&](int& x,int &y)
        {
            return (x >=0 && x < rows && y>=0 && y < cols && grid[x][y]!='0');
        };
        
        for(auto& dir: directions)
        {
            int newX = x+dir[0];
            int newY = y+dir[1];
            if(isSafe(newX, newY))
            {
                grid[newX][newY] = '0';
                dfs(rows,cols,newX,newY,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int ans = 0;
        for(int i = 0;i<rows;i++)
        {
            for(int j = 0;j < cols;j++)
            {
                if(grid[i][j] == '1')
                {
                    ++ans;
                    dfs(rows,cols,i,j,grid);
                }
            }
        }
        
        return ans;
    }
};
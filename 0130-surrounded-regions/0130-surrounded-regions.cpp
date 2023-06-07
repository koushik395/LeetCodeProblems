class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int i,int j,int rows,int cols)
    { 
        if(i>=0 && i<rows && j>=0 && j<cols && grid[i][j]=='O' && visited[i][j] == 0)
        {
            visited[i][j] = 1;
            dfs(grid,visited,i-1,j,rows,cols);
            dfs(grid,visited,i+1,j,rows,cols);
            dfs(grid,visited,i,j+1,rows,cols);
            dfs(grid,visited,i,j-1,rows,cols);   
        }
    }
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0;i< n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 'O')
                    if(i==0 || i == n-1 || j==0 || j == m-1)
                    {
                        dfs(grid,visited,i,j,n,m);   
                    }
            }
        }
        
        for(int i = 0;i< n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='O')
                {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};
class Solution {
public:
    vector<vector<int>> direc = {{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>& grid,int i ,int j,int row,int col)
    {
        if(i < 0 || j < 0 || i == row || j == col || grid[i][j]==0) return 0;
        
        int total = 0;
        if(grid[i][j] >0)
        {
            total = grid[i][j];
            grid[i][j] = 0;
            for(auto& it:direc)
            {
                int nx = i + it[0];
                int ny = j + it[1];
                total +=  dfs(grid,nx,ny,row,col);
            }   
        }
        return total;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int maxi = -1;
        for(int i = 0; i < row;i++)
        {
            for(int j = 0;j < col;j++)
            {
                maxi = max(maxi,dfs(grid,i,j,row,col));
            }
        }
        return maxi;
    }
};
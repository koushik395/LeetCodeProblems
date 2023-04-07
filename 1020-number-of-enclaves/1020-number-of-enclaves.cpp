class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans=0;
        for(int i = 0;i< rows;i++)
        {
            for(int j = 0;j < cols;j++)
            {
                if(grid[i][j] == 1)
                    if(i==0 || i == rows-1 || j==0 || j == cols-1)
                        FloodFill(grid,i,j,rows,cols);
            }
        }
        //after filling count the remaining lands
        for(auto &row:grid)
            for(auto &col:row)
                if(col == 1)
                    ans++;
        return ans;
        
    }
    void FloodFill(vector<vector<int>>& grid,int i,int j,int rows,int cols)
    { 
        //fill all the lands that are connected to perimeter with water.
        if(i>=0 && i<rows && j>=0 && j<cols && grid[i][j]==1)
        {
            grid[i][j] = 0;
            FloodFill(grid,i-1,j,rows,cols);
            FloodFill(grid,i+1,j,rows,cols);
            FloodFill(grid,i,j+1,rows,cols);
            FloodFill(grid,i,j-1,rows,cols);   
        }
    }
    
};
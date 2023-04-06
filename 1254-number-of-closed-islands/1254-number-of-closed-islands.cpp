class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans=0;
        for(int i = 1;i< rows - 1;i++)
        {
            for(int j = 1;j < cols-1;j++)
            {
                if(grid[i][j]==0)
                {
                    if(isPossible(grid,i,j,rows,cols))
                        ans++;
                }
            }
        }
        return ans;
    }
    
    bool isPossible(vector<vector<int>>& grid,int i,int j,int rows,int cols)
    {
        //0 land
        //1 water
        //-1 visited
        if(grid[i][j]== -1 || grid[i][j]== 1) return true;
        
        // check if land is in perimeter
        if(isPerimeter(i,j,rows,cols)) return false;
        
        grid[i][j] = -1;
        
        int left = isPossible(grid,i,j-1,rows,cols);
        int right = isPossible(grid,i,j+1,rows,cols);
        int up = isPossible(grid,i-1,j,rows,cols);
        int down = isPossible(grid,i+1,j,rows,cols);
        
        return left && right && up && down;
    }
    
    bool isPerimeter(int i,int j,int rows,int cols)
    {
        return i==0 || i == rows-1 || j==0 || j == cols-1;
    }
};
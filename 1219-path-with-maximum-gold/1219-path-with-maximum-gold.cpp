class Solution {
public:
    vector<vector<int>> direc = {{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(int i,int j,vector<vector<int>> &grid,int n,int m)
    {
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0) return 0;
        
        int total = 0;
        total = grid[i][j];
        int val = grid[i][j];
        grid[i][j] = 0;
        
        int maxi = -1;
        for(auto& it: direc)
        {
            int newx = i + it[0];
            int newy = j + it[1];
            
            maxi = max(maxi,dfs(newx,newy,grid,n,m));
        }
        total = total +maxi;
        grid[i][j] = val;
        return total;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m  = grid[0].size();
        
        int maxi = 0;;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] > 0)
                {
                    maxi = max(maxi,dfs(i,j,grid,n,m));   
                }
            }
        }
        return maxi;
    }
};
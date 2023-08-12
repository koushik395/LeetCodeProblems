class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& heights,vector<vector<bool>> &visited,int x,int y)
    {
        visited[x][y] = true;
        
        //up
        if(x-1 >= 0 && !visited[x-1][y] && heights[x-1][y] >= heights[x][y])
        {
            dfs(heights,visited,x-1,y);
        }
        
        //down
        if(x+1 <= n-1 && !visited[x+1][y] && heights[x+1][y] >= heights[x][y])
        {
            dfs(heights,visited,x+1,y);
        }
        
        //left
        if(y-1 >= 0 && !visited[x][y-1] && heights[x][y-1] >= heights[x][y])
        {
            dfs(heights,visited,x,y-1);
        }
        
        //right
        if(y+1 <= m-1 && !visited[x][y+1] && heights[x][y+1] >= heights[x][y])
        {
            dfs(heights,visited,x,y+1);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        n = heights.size();
        m = heights[0].size();
        
        vector<vector<bool>> pacific(n,vector<bool>(m));
        vector<vector<bool>> atlantic(n,vector<bool>(m));
        
        for(int i = 0;i < n;i++)
        {
            dfs(heights,pacific,i,0);
            dfs(heights,atlantic,i,m-1);
        }
        
        for(int j = 0;j < m;j++)
        {
            dfs(heights,pacific,0,j);
            dfs(heights,atlantic,n-1,j);
        }
        
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    } 
};
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isPossible(vector<vector<int>>& cells,int row,int col,int mid)
    {
        vector<vector<bool>> grid(row,vector<bool>(col,0));
        for(int i =  0;i < mid;i++)
        {
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        queue<pair<int,int>> q;
        for(int i = 0;i < col;i++)
        {
            if(grid[0][i] == 0)
            {
                q.push({0,i});
                grid[0][i] = 1;
            }
        }
        
        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();
            if(r == row-1) return true;
            for(auto& it: directions)
            {
                int nr = r + it[0];
                int nc = c + it[1];
                if(nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc]==1) continue;
                grid[nr][nc] = 1;
                q.push({nr,nc});
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 1,high = cells.size(),mid,ans = 0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(cells,row,col,mid))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};